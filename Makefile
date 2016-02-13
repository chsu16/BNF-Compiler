# $Id: Makefile,v 1.12 2015-07-09 18:41:17-07 - - $

DEPSFILE  = Makefile.deps
NOINCLUDE = ci clean spotless
NEEDINCL  = ${filter ${NOINCLUDE}, ${MAKECMDGOALS}}
CPP       = g++ -g -O0  -std=gnu++11
MKDEPS    = g++ -MM -std=gnu++11
GRIND     = valgrind --leak-check=full --show-reachable=yes
FLEX      = flex --header-file=${LEXHDR} --outfile=${LEXCPP}
BISON     = bison --defines=${PARSEHDR} --output=${PARSECPP}

MODULES   = astree auxlib lyutils stringset traverse symbol-table-code gencode
HDRSRC    = ${MODULES:=.h}
CPPSRC    = ${MODULES:=.cpp} oc.cpp
FLEXSRC   = scanner.l
BISONSRC  = parser.y
LEXHDR    = yylex.h
PARSEHDR  = yyparse.h
LEXCPP    = yylex.cpp
PARSECPP  = yyparse.cpp
CGENS     = ${LEXCPP} ${PARSECPP}
ALLGENS   = ${LEXHDR} ${CGENS}
EXECBIN   = oc
ALLCSRC   = ${CPPSRC} ${CGENS}
OBJECTS   = ${ALLCSRC:.cpp=.o}
LEXOUT    = yylex.output
PARSEOUT  = yyparse.output
REPORTS   = ${LEXOUT} ${PARSEOUT}
MODSRC    = ${foreach MOD, ${MODULES}, ${MOD}.h ${MOD}.cpp}
MISCSRC   = ${filter-out ${MODSRC}, ${HDRSRC} ${CPPSRC}}
ALLSRC    = README ${FLEXSRC} ${BISONSRC} ${MODSRC} ${MISCSRC} Makefile
TESTINS   = ${wildcard test*.in}
EXECTEST  = ${EXECBIN} -ly
LISTSRC   = ${ALLSRC} ${DEPSFILE} ${PARSEHDR}

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${CPP} -o${EXECBIN} ${OBJECTS}

%.o : %.cpp
	${CPP} -c $<

${LEXCPP} : ${FLEXSRC}
	${FLEX} ${FLEXSRC} 2>${LEXOUT}
	- grep -v '^  ' ${LEXOUT}

${PARSECPP} ${PARSEHDR} : ${BISONSRC}
	${BISON} ${BISONSRC}
	

ci : ${ALLSRC} ${TESTINS}
	- checksource ${ALLSRC}
	- cpplint.py.perl ${CPPSRC}
	cid + ${ALLSRC} ${TESTINS} test?.inh

lis : ${LISTSRC} tests
	mkpspdf List.source.ps ${LISTSRC}
	mkpspdf List.output.ps ${REPORTS} \
		${foreach test, ${TESTINS:.in=}, \
		${patsubst %, ${test}.%, in out err log}}

clean :
	- rm ${OBJECTS} ${ALLGENS} ${REPORTS} ${DEPSFILE} core
	- rm ${foreach test, ${TESTINS:.in=}, \
		${patsubst %, ${test}.%, out err log}}

spotless : clean
	- rm ${EXECBIN} List.*.ps List.*.pdf

deps : ${ALLCSRC}
	@ echo "# ${DEPSFILE} created `date` by ${MAKE}" >${DEPSFILE}
	${MKDEPS} ${ALLCSRC} >>${DEPSFILE}

${DEPSFILE} :
	@ touch ${DEPSFILE}
	${MAKE} --no-print-directory deps

tests : ${EXECBIN}
	touch ${TESTINS}
	make --no-print-directory ${TESTINS:.in=.out}

%.out %.err : %.in ${EXECBIN}
	${GRIND} --log-file=$*.log ${EXECTEST} $< 1>$*.out 2>$*.err; \
	echo EXIT STATUS = $$? >>$*.log

again :
	gmake --no-print-directory spotless deps ci all lis
	


﻿#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2024-05-03 21:36:38.076653
#

OUTDIR		:= build-dir

CC          := gcc
CC_FLAGS    := -Wno-parentheses -xc -Werror -std=c11 -fdiagnostics-color -Wno-error=parentheses -ggdb3 -D_ANSI_OUTPUT -fmax-errors=5 -D_GNU_SOURCE -Wno-error=implicit-fallthrough -DINSIDE_DANTE -Werror=vla -Wno-error=unused-parameter -pedantic -Wextra -Wall 
#CC_FLAGS    += -Werror=vla -Wno-error=unused-parameter -Wno-error=parentheses -Wno-parentheses -Wno-error=implicit-fallthrough
#CC_FLAGS    += -D_GNU_SOURCE -D_TEST_BOOTSTRAP -DINSIDE_DANTE
#CC_FLAGS    += -D_NO_HTML_OUTPUT -D_ANSI_OUTPUT

LD          := gcc
LD_FLAGS    := -ggdb3 -Wl,-cref -Wl,-Map=main.map -Wl,-wrap,main 
LD_LIBS     := -lm 

RM          := rm -rf
MKDIR       := mkdir -p

default: # Domyślny target - pomoc
	@echo "Brak określonego celu budowania lub uruchomienia. Dostępne są możliwości:"
	@echo "    make build          - Budowa pliku wykonywalnego"
	@echo "    make rebuild        - Przebudowa pliku wykonywalnego"
	@echo "    make clean          - Usunięcie pliku wykonywalnego i plików pośrenidch"
	@echo "    make run_main       - Uruchomienie przesłanej funkcji main()"
	@echo "    make run_main_tests - Uruchomienie testów funkcji main()"
	@echo "    make run_unit_tests - Uruchomienie testów jednostkowych"
	@echo ""


# Target: podstawowe uruchomienie całego programu
all: run_main

.PHONY: all

# Target: Uruchomienie przesłanej funkcji main()
run_main: build
	${OUTDIR}/main 0

# Target: Uruchomienie testów jednostkowych
run_unit_tests: build
	${OUTDIR}/main 1

# Target: Uruchomienie testów funkcji main()
run_main_tests: build
	${OUTDIR}/main 2

# Target: Przebudowa pliku wykonywalnego
rebuild: clean build

# Target: Budowa pliku wykonywalnego
build: .prepare ${OUTDIR}/main

#
# Kompilacja i konsolidacja przesłanego programu
#

${OUTDIR}/main: ${OUTDIR}/main.c.o ${OUTDIR}/array.c.o ${OUTDIR}/unit_helper_v2.c.o ${OUTDIR}/unit_test_v2.c.o ${OUTDIR}/rdebug.c.o 
	@echo "Konsolidacja..."
	@${LD} ${LD_FLAGS} ${OUTDIR}/main.c.o ${OUTDIR}/array.c.o ${OUTDIR}/unit_helper_v2.c.o ${OUTDIR}/unit_test_v2.c.o ${OUTDIR}/rdebug.c.o  -o ${OUTDIR}/main ${LD_LIBS}


${OUTDIR}/main.c.o:  main.c
	@echo "Budowanie pliku 'main.o' z 'main.c'..."
	${CC} ${CC_FLAGS} -c main.c -o ${OUTDIR}/main.c.o

${OUTDIR}/array.c.o:  array.c
	@echo "Budowanie pliku 'array.o' z 'array.c'..."
	${CC} ${CC_FLAGS} -c array.c -o ${OUTDIR}/array.c.o

${OUTDIR}/unit_helper_v2.c.o:  unit_helper_v2.c
	@echo "Budowanie pliku 'unit_helper_v2.o' z 'unit_helper_v2.c'..."
	${CC} ${CC_FLAGS} -c unit_helper_v2.c -o ${OUTDIR}/unit_helper_v2.c.o

${OUTDIR}/unit_test_v2.c.o:  unit_test_v2.c
	@echo "Budowanie pliku 'unit_test_v2.o' z 'unit_test_v2.c'..."
	${CC} ${CC_FLAGS} -c unit_test_v2.c -o ${OUTDIR}/unit_test_v2.c.o

${OUTDIR}/rdebug.c.o:  rdebug.c
	@echo "Budowanie pliku 'rdebug.o' z 'rdebug.c'..."
	${CC} ${CC_FLAGS} -c rdebug.c -o ${OUTDIR}/rdebug.c.o


.PHONY: build rebuild run_main run_main_tests run_unit_tests clean


#
# Przygotownie środowiska
#

.prepare: ${OUTDIR}

${OUTDIR}:
	${MKDIR} ${OUTDIR}

clean:
	${RM} ${OUTDIR}


.PHONY: prepare clean
.PHONY: build rebuild
.PHONY: run_unit_tests run_main_tests run_main
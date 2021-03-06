#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sources/BD/acoes_funcionario_bd.o \
	${OBJECTDIR}/Sources/BD/bd.o \
	${OBJECTDIR}/Sources/BD/caixa_bd.o \
	${OBJECTDIR}/Sources/BD/empresa_bd.o \
	${OBJECTDIR}/Sources/BD/fabricante_bd.o \
	${OBJECTDIR}/Sources/BD/funcionario_bd.o \
	${OBJECTDIR}/Sources/BD/grupo_bd.o \
	${OBJECTDIR}/Sources/BD/produto_bd.o \
	${OBJECTDIR}/Sources/MENU/cupom_fiscal/formatacao_cupom.o \
	${OBJECTDIR}/Sources/MENU/cupom_fiscal/horario_cupom.o \
	${OBJECTDIR}/Sources/MENU/menu.o \
	${OBJECTDIR}/Sources/MODELO/empresa.o \
	${OBJECTDIR}/Sources/MODELO/fabricante.o \
	${OBJECTDIR}/Sources/MODELO/funcionario.o \
	${OBJECTDIR}/Sources/MODELO/produto.o \
	${OBJECTDIR}/Sources/UTIL/alocacao_memoria.o \
	${OBJECTDIR}/Sources/UTIL/horario.o \
	${OBJECTDIR}/Sources/UTIL/my_string.o \
	${OBJECTDIR}/Sources/UTIL/planilhas.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trabalhofinalpc2

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trabalhofinalpc2: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trabalhofinalpc2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Sources/BD/acoes_funcionario_bd.o: Sources/BD/acoes_funcionario_bd.c
	${MKDIR} -p ${OBJECTDIR}/Sources/BD
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/BD/acoes_funcionario_bd.o Sources/BD/acoes_funcionario_bd.c

${OBJECTDIR}/Sources/BD/bd.o: Sources/BD/bd.c
	${MKDIR} -p ${OBJECTDIR}/Sources/BD
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/BD/bd.o Sources/BD/bd.c

${OBJECTDIR}/Sources/BD/caixa_bd.o: Sources/BD/caixa_bd.c
	${MKDIR} -p ${OBJECTDIR}/Sources/BD
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/BD/caixa_bd.o Sources/BD/caixa_bd.c

${OBJECTDIR}/Sources/BD/empresa_bd.o: Sources/BD/empresa_bd.c
	${MKDIR} -p ${OBJECTDIR}/Sources/BD
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/BD/empresa_bd.o Sources/BD/empresa_bd.c

${OBJECTDIR}/Sources/BD/fabricante_bd.o: Sources/BD/fabricante_bd.c
	${MKDIR} -p ${OBJECTDIR}/Sources/BD
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/BD/fabricante_bd.o Sources/BD/fabricante_bd.c

${OBJECTDIR}/Sources/BD/funcionario_bd.o: Sources/BD/funcionario_bd.c
	${MKDIR} -p ${OBJECTDIR}/Sources/BD
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/BD/funcionario_bd.o Sources/BD/funcionario_bd.c

${OBJECTDIR}/Sources/BD/grupo_bd.o: Sources/BD/grupo_bd.c
	${MKDIR} -p ${OBJECTDIR}/Sources/BD
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/BD/grupo_bd.o Sources/BD/grupo_bd.c

${OBJECTDIR}/Sources/BD/produto_bd.o: Sources/BD/produto_bd.c
	${MKDIR} -p ${OBJECTDIR}/Sources/BD
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/BD/produto_bd.o Sources/BD/produto_bd.c

${OBJECTDIR}/Sources/MENU/cupom_fiscal/formatacao_cupom.o: Sources/MENU/cupom_fiscal/formatacao_cupom.c
	${MKDIR} -p ${OBJECTDIR}/Sources/MENU/cupom_fiscal
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/MENU/cupom_fiscal/formatacao_cupom.o Sources/MENU/cupom_fiscal/formatacao_cupom.c

${OBJECTDIR}/Sources/MENU/cupom_fiscal/horario_cupom.o: Sources/MENU/cupom_fiscal/horario_cupom.c
	${MKDIR} -p ${OBJECTDIR}/Sources/MENU/cupom_fiscal
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/MENU/cupom_fiscal/horario_cupom.o Sources/MENU/cupom_fiscal/horario_cupom.c

${OBJECTDIR}/Sources/MENU/menu.o: Sources/MENU/menu.c
	${MKDIR} -p ${OBJECTDIR}/Sources/MENU
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/MENU/menu.o Sources/MENU/menu.c

${OBJECTDIR}/Sources/MODELO/empresa.o: Sources/MODELO/empresa.c
	${MKDIR} -p ${OBJECTDIR}/Sources/MODELO
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/MODELO/empresa.o Sources/MODELO/empresa.c

${OBJECTDIR}/Sources/MODELO/fabricante.o: Sources/MODELO/fabricante.c
	${MKDIR} -p ${OBJECTDIR}/Sources/MODELO
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/MODELO/fabricante.o Sources/MODELO/fabricante.c

${OBJECTDIR}/Sources/MODELO/funcionario.o: Sources/MODELO/funcionario.c
	${MKDIR} -p ${OBJECTDIR}/Sources/MODELO
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/MODELO/funcionario.o Sources/MODELO/funcionario.c

${OBJECTDIR}/Sources/MODELO/produto.o: Sources/MODELO/produto.c
	${MKDIR} -p ${OBJECTDIR}/Sources/MODELO
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/MODELO/produto.o Sources/MODELO/produto.c

${OBJECTDIR}/Sources/UTIL/alocacao_memoria.o: Sources/UTIL/alocacao_memoria.c
	${MKDIR} -p ${OBJECTDIR}/Sources/UTIL
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/UTIL/alocacao_memoria.o Sources/UTIL/alocacao_memoria.c

${OBJECTDIR}/Sources/UTIL/horario.o: Sources/UTIL/horario.c
	${MKDIR} -p ${OBJECTDIR}/Sources/UTIL
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/UTIL/horario.o Sources/UTIL/horario.c

${OBJECTDIR}/Sources/UTIL/my_string.o: Sources/UTIL/my_string.c
	${MKDIR} -p ${OBJECTDIR}/Sources/UTIL
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/UTIL/my_string.o Sources/UTIL/my_string.c

${OBJECTDIR}/Sources/UTIL/planilhas.o: Sources/UTIL/planilhas.c
	${MKDIR} -p ${OBJECTDIR}/Sources/UTIL
	${RM} "$@.d"
	$(COMPILE.c) -O2 -std=c89 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/UTIL/planilhas.o Sources/UTIL/planilhas.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

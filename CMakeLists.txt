cmake_minimum_required(VERSION 3.0)
project(TP01-AEDS2)

set(SOURCES tipoPalavra.c tipoPalavra.h listaEncadPares.c listaEncadPares.h hashTablePalavras.c hashTablePalavras.h)
add_executable(testesJoao testesJoao.c ${SOURCES})
cmake_minimum_required(VERSION 3.10)
project(TP01-AEDS2)

set(SOURCES tipoPalavra.c tipoPalavra.h listaEncadPares.c listaEncadPares.h)
add_executable(testeGuto testesGuto.c ${SOURCES})

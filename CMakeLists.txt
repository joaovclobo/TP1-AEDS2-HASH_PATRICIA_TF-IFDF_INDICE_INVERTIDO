cmake_minimum_required(VERSION 3.21)
project(TP1_AEDS2)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES hashTablePalavras.c hashTablePalavras.h tipoPalavra.c tipoPalavra.h listaEncadDocs.c listaEncadDocs.h listaEncadPares.c listaEncadPares.h main.c operacoesIndiceInvertido.c operacoesIndiceInvertido.h patricia.c patricia.h)
add_executable(main ${SOURCE_FILES})
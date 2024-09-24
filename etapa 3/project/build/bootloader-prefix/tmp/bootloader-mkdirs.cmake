# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/lucas/esp/v5.1-rc2/esp-idf/components/bootloader/subproject"
  "/Users/lucas/Documents/Projeto-sistemas-embarcados/etapa 3/project/build/bootloader"
  "/Users/lucas/Documents/Projeto-sistemas-embarcados/etapa 3/project/build/bootloader-prefix"
  "/Users/lucas/Documents/Projeto-sistemas-embarcados/etapa 3/project/build/bootloader-prefix/tmp"
  "/Users/lucas/Documents/Projeto-sistemas-embarcados/etapa 3/project/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/lucas/Documents/Projeto-sistemas-embarcados/etapa 3/project/build/bootloader-prefix/src"
  "/Users/lucas/Documents/Projeto-sistemas-embarcados/etapa 3/project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/lucas/Documents/Projeto-sistemas-embarcados/etapa 3/project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/lucas/Documents/Projeto-sistemas-embarcados/etapa 3/project/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
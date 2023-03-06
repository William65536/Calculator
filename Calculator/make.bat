@ECHO OFF

SET CC=clang
SET FLAGS=-g -Wall -Wextra -Wpedantic -Werror -std=c11
SET SRC=Project\src

%CC% -c %FLAGS% -o %SRC%\String.o %SRC%\String.c

%CC% -c %FLAGS% -o %SRC%\Token.o %SRC%\Token.c

%CC% -c %FLAGS% -o Project\main.o Project\main.c
%CC% -o Project\main %SRC%\String.o %SRC%\Token.c Project\main.o

DEL Project\main.o %SRC%\String.o %SRC%\Token.c

Project\main

ECHO: & ECHO: & ECHO:

IF ERRORLEVEL 1 (
    ECHO PROGRAM ERROR %ERRORLEVEL%
) ELSE IF ERRORLEVEL 0 (
    ECHO SUCCESS 0
) ELSE (
    ECHO SYSTEM ERROR %ERRORLEVEL%
)
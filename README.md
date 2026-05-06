# MiniCalc: A Custom DSL Compiler using Flex, Bison, C and LLVM

## Introduction
MiniCalc is a custom Domain Specific Language (DSL) compiler developed using Flex, Bison, C and LLVM.

The compiler performs:
- Lexical Analysis
- Syntax Parsing
- Semantic Analysis
- AST Construction
- LLVM IR Generation
- Native Executable Generation

## Technologies Used
- C
- Flex
- Bison
- LLVM
- Clang
- GitHub

## Compiler Pipeline
Source Code → Lexer → Parser → AST → Semantic Analysis → LLVM IR → Assembly → Executable

## Build Commands

```bash
make
make run
## LLVM IR Generation

```bash
llc output/output.ll -o output/output.s
```

## Executable Generation

```bash
clang output/output.s -o output/executable
```
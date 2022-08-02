project('prl', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

cmake = import('cmake')

#antlr4 runtime
sub_proj = cmake.subproject('antlr4-cpp-runtime')
parser_lib = sub_proj.dependency('antlr4_cpp_runtime')

#argparse
sub_proj = cmake.subproject('argparse')
argparse_lib = sub_proj.dependency('argparse')

subdir('grammar/antlr4-runtime')

exe = executable('prl',
           'Symbol.cpp',
           'Cartridge.cpp',
           'Match.cpp',
           'Pattern.cpp',
           'main.cpp',
           'Rule.cpp',
           'ParserVisitor.cpp',
           parser_sources,
           dependencies : [
            parser_lib,
            argparse_lib
           ],
           install : true)

#test example projects
test('islands', exe, args: ['/Users/andreacolledan/Projects/pattern-rewriting-language/examples/islands.prl'])
test('dungeon', exe, args: ['/Users/andreacolledan/Projects/pattern-rewriting-language/examples/dungeon.prl'])
test('house', exe, args: ['/Users/andreacolledan/Projects/pattern-rewriting-language/examples/house.prl'])

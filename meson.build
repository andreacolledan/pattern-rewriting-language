project('prl', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

cmake = import('cmake')

# Configure the CMake project
sub_proj = cmake.subproject('antlr4-cpp-runtime')

# Fetch the dependency object
parser_lib = sub_proj.dependency('antlr4_cpp_runtime')

subdir('grammar/antlr4-runtime')

executable('prl',
           'Symbol.cpp',
           'Cartridge.cpp',
           'Match.cpp',
           'Pattern.cpp',
           'main.cpp',
           'Rule.cpp',
           'ParserVisitor.cpp',
           parser_sources,
           dependencies : parser_lib,
           install : true)

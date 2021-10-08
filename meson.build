project('sample', 'c', 'cpp',
default_options : [
        'c_std=c11',
        'cpp_std=c++17',
        'objcpp_args=-std=c++17 -Wno-deprecated',
        'default_library=static'
    ]
)

sample_sources = files(
    './sample/benchmark.cpp',
    './sample/sample.cpp'
    
)

sample_headers = files(
    './sample/benchmark.h'
)

cpp = meson.get_compiler('cpp')

message('cpp = @0@'.format(cpp.get_id()))

if host_machine.system() == 'windows'
    add_project_arguments('-DUNICODE', '-D_UNICODE','-std:c++latest', language: ['c', 'cpp'])
endif

sample_inc = include_directories('./sample')

executable('sample',extra_files: [ sample_headers ], sources: [ sample_sources])
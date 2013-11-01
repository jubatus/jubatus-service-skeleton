#!/usr/bin/env python

from subprocess import call

name = 'kvs'

def options(opt):
  opt.load('compiler_cxx')

def generate(ctx):
  call(['jenerator', '-l', 'server', '-o', '.', '-n', 'jubatus', '-t', name + '.idl'])
  call(['jenerator', '-l', 'cpp', '-o', '.', '-n', 'jubatus', '-t', name + '.idl'])

def clean_generated(ctx):
  generated = [
    name + '_client.hpp',
    name + '_types.hpp',
    name + '_impl.cpp',
    name + '_proxy.cpp',
    name + '_serv.tmpl.cpp',
    name + '_serv.tmpl.hpp',
  ]
  for f in generated:
    ctx.path.make_node(f).delete()

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
  conf.load('compiler_cxx')

  conf.check_cfg(package = 'jubatus', args = '--cflags --libs')
  conf.check_cfg(package = 'jubatus-client', args = '--cflags --libs')

def build(bld):
  bld.program(
    source = [name+'_serv.cpp', name+'_impl.cpp'],
    target = name,
    use = ['JUBATUS'],
    )

  bld.program(
    source = name+'_proxy.cpp',
    target = name+'_proxy',
    use = ['JUBATUS'],
    )

  bld.program(
    source = 'client.cpp',
    target = 'client',
    use = ['JUBATUS-CLIENT'],
    )

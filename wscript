#!/usr/bin/env python

from subprocess import call

name = 'kvs'

def options(opt):
  opt.load('compiler_cxx')

def generate(ctx):
  call(['jenerator', name + '.idl', '-o', '.', '-t'])
  call(['mpidl', 'cpp', name + '.idl', '-o', '.', '-p', '-n', 'jubatus'])
  call(['mpidlconv', '-i', '.', '-s', name])

def clean_generated(ctx):
  generated = [
    name + '_client.hpp',
    name + '_types.hpp',
    name + '_impl.cpp',
    name + '_keeper.cpp',
    name + '_server.hpp',
    name + '_serv.tmpl.cpp',
    name + '_serv.tmpl.hpp',
  ]
  for f in generated:
    ctx.path.make_node(f).delete()

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
  conf.load('compiler_cxx')

  conf.check_cxx(lib = 'msgpack', mandatory = True)
  conf.check_cxx(lib = 'glog', mandatory = True)

  conf.check_cxx(lib = 'pficommon', mandatory = True)
  conf.check_cxx(lib = 'pficommon_system', mandatory = True)
  conf.check_cxx(lib = 'pficommon_concurrent', mandatory = True)
  conf.check_cxx(lib = 'pficommon_lang', mandatory = True)
  conf.check_cxx(lib = 'pficommon_text', mandatory = True)

  conf.check_cxx(lib = 'jubatus_mpio', mandatory = True)
  conf.check_cxx(lib = 'jubatus_msgpack-rpc', mandatory = True)

  conf.check_cxx(lib = 'jubatus_framework', mandatory = True)
  conf.check_cxx(lib = 'jubacommon', mandatory = True)
  conf.check_cxx(lib = 'jubacommon_mprpc', mandatory = True)
  conf.check_cxx(lib = 'jubamixer', mandatory = True)

def build(bld):
  bld.program(
    source = [name+'_serv.cpp', name+'_impl.cpp'],
    target = name,
    use = ['JUBATUS_FRAMEWORK', 'JUBACOMMON', 'JUBACOMMON_MPRPC', 'JUBAMIXER',
           'PFICOMMON', 'PFICOMMON_SYSTEM', 'PFICOMMON_CONCURRENT', 'PFICOMMON_LANG', 'PFICOMMON_TEXT',
           'JUBATUS_MPIO', 'JUBATUS_MSGPACK-RPC',
           'MSGPACK', 'GLOG']
    )

  bld.program(
    source = name+'_keeper.cpp',
    target = name+'_keeper',
    use = ['JUBATUS_FRAMEWORK', 'JUBACOMMON', 'JUBACOMMON_MPRPC',
           'PFICOMMON', 'PFICOMMON_SYSTEM', 'PFICOMMON_CONCURRENT',
           'JUBATUS_MPIO', 'JUBATUS_MSGPACK-RPC',
           'MSGPACK', 'GLOG']
    )

  bld.program(
    source = 'client.cpp',
    target = 'client',
    use = ['PFICOMMON', 'PFICOMMON_SYSTEM',
           'JUBATUS_MPIO', 'JUBATUS_MSGPACK-RPC',
           'MSGPACK']
    )

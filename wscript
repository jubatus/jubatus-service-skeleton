#!/usr/bin/env python

from subprocess import call

name = 'kvs'

def options(opt):
  opt.load('compiler_cxx')

def generate(ctx):
  call(['jenerator', name + '.idl', '-o', '.', '-t'])
  call(['mpidl', 'cpp', name + '.idl', '-o', '.', '-p', '-n', 'jubatus'])

def configure(conf):
  conf.env.CXXFLAGS += ['-O2', '-Wall', '-g', '-pipe']
  conf.load('compiler_cxx')

  conf.check_cxx(lib = 'msgpack', mandatory = True)
  conf.check_cxx(lib = 'event', mandatory = True)
  conf.check_cxx(lib = 'glog', mandatory = True)

  conf.check_cxx(lib = 'pficommon', mandatory = True)
  conf.check_cxx(lib = 'pficommon_system', mandatory = True)
  conf.check_cxx(lib = 'pficommon_concurrent', mandatory = True)
  conf.check_cxx(lib = 'pficommon_network_mprpc', mandatory = True)

  conf.check_cxx(lib = 'jubatus_framework', mandatory = True)
  conf.check_cxx(lib = 'jubacommon', mandatory = True)
  conf.check_cxx(lib = 'jubacommon_mprpc', mandatory = True)
  conf.check_cxx(lib = 'jubamixer', mandatory = True)

def build(bld):
  bld.program(
    source = [name+'_serv.cpp', name+'_impl.cpp'],
    target = name,
    use = ['JUBATUS_FRAMEWORK', 'JUBACOMMON', 'JUBACOMMON_MPRPC', 'JUBAMIXER',
           'PFICOMMON', 'PFICOMMON_SYSTEM', 'PFICOMMON_CONCURRENT', 'PFICOMMON_NETWORK_MPRPC',
           'MSGPACK', 'EVENT', 'GLOG']
    )

  bld.program(
    source = name+'_keeper.cpp',
    target = name+'_keeper',
    use = ['JUBATUS_FRAMEWORK', 'JUBACOMMON', 'JUBACOMMON_MPRPC',
           'PFICOMMON', 'PFICOMMON_SYSTEM', 'PFICOMMON_CONCURRENT', 'PFICOMMON_NETWORK_MPRPC',
           'MSGPACK', 'EVENT', 'GLOG']
    )

  bld.program(
    source = 'client.cpp',
    target = 'client',
    use = ['PFICOMMON', 'PFICOMMON_SYSTEM', 'PFICOMMON_NETWORK_MPRPC',
           'MSGPACK']
    )

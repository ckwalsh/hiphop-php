/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef __HPHP_EVAL_DEBUGGER_CMD_RUN_H__
#define __HPHP_EVAL_DEBUGGER_CMD_RUN_H__

#include <runtime/eval/debugger/debugger_command.h>

namespace HPHP { namespace Eval {
///////////////////////////////////////////////////////////////////////////////

DECLARE_BOOST_TYPES(CmdRun);
class CmdRun : public DebuggerCommand {
public:
  CmdRun() : DebuggerCommand(KindOfRun) {}

  virtual void list(DebuggerClient *client);
  virtual bool help(DebuggerClient *client);

  virtual bool onClient(DebuggerClient *client);
  virtual bool onServer(DebuggerProxy *proxy);

  virtual void sendImpl(DebuggerThriftBuffer &thrift);
  virtual void recvImpl(DebuggerThriftBuffer &thrift);

private:
  StringVecPtr m_args;
};

///////////////////////////////////////////////////////////////////////////////
}}

#endif // __HPHP_EVAL_DEBUGGER_CMD_RUN_H__

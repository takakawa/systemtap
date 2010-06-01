// -*- C++ -*-
// Copyright (C) 2010 Red Hat Inc.
//
// This file is part of systemtap, and is free software.  You can
// redistribute it and/or modify it under the terms of the GNU General
// Public License (GPL); either version 2, or (at your option) any
// later version.
#ifndef CSCLIENT_H
#define CSCLIENT_H

struct systemtap_session;
struct compile_server_info;

class compile_server_client
{
public:
  compile_server_client (systemtap_session &s) : s(s) {}
  int passes_0_4 ();

private:
  // Client/server session methods.
  int initialize ();
  int create_request ();
  int package_request ();
  int find_and_connect_to_server ();
  int unpack_response ();
  int process_response ();

  // Client/server utility methods.
  int include_file_or_directory (
    const std::string &subdir,
    const std::string &path,
    const char *option = 0
  );
  void add_package_args ();
  void add_package_arg (const std::string &arg);
  void write_to_file (const std::string &fname, const std::string &data);
  int  compile_using_server (const compile_server_info &server);

  systemtap_session &s;
  std::vector<std::string> private_ssl_dbs;
  std::vector<std::string> public_ssl_dbs;
  std::string client_tmpdir;
  std::string client_zipfile;
  std::string server_tmpdir;
  std::string server_zipfile;
  unsigned argc;
};

#endif // CSCLIENT_H
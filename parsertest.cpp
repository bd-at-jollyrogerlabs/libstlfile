/* $Id$ -*- mode: c++; c-basic-offset 2; -*- */
/*
 * Test program for Stereolithography (.stl) file parser.
 *
 * Copyright 2014 Brian Davis.
 * All rights reserved.
 */

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cerrno>
#include <cassert>

#include "StlFileProcessor.h"

using namespace std;
using namespace libstlfile;

class TestStlFileProcessor : public StlFileProcessor
{
public:
  TestStlFileProcessor()
    : count_(0)
  {
  }

  virtual void
  addTriangle(const Vec3 normals,
	      const Vec3 v1,
	      const Vec3 v2,
	      const Vec3 v3)
  {
    ++count_;
  }

  virtual void
  setSolidName(const string &name)
  {
    name_ = name;
  }

  unsigned
  getCount() const
  {
    return count_;
  }

private:
  string name_;
  unsigned count_;
};

int
main(const int argc, const char *argv[])
{
  assert(2 == argc);
  TestStlFileProcessor processor;
  const int result = processor.processFile(argv[1]);
  if (0 == result) {
    cout << "Count = " << processor.getCount() << endl;
  }
  return result;
}

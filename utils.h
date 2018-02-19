//
// Created by lfrances on 06-Feb-18.
//

#ifndef CPPSTACK_UTILS_H
#define CPPSTACK_UTILS_H

bool checkArgs(int argc, char **argv);

bool checkArgs(int argc, char **argv) { return argc < 2 ? false : true; }

#endif // CPPSTACK_UTILS_H

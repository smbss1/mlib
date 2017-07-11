/*
 * Copyright (c) 2017, Patrick Pelissier
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * + Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * + Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* Coverage helper header.
   Computing coverage for a generic macro expansing library is not trivial
   as there is no tool to do it normally.

   That's why a special way has been designed:
   *) Put the code to coverage within the macros START_COVERAGE & END_COVERAGE
   (without forgetting to include the header coverage.h before)
   #include "coverage.h"
   START_COVERAGE
   [code to be expanded & to be coveraged]
   END_COVERAGE

   Run the coverage in the makefile like this:
   *) make coverage-test/test-marray.c
   
   View the coverage file test-marray.c.gcov
   It'll contain the macro expanded & annotated.
*/
   
#ifdef WITHIN_COVERAGE
/* For coverage build, do not expand the
   typical macros assert, NULL, etc. */
#undef assert
#undef NULL
#undef M_LIKELY
#undef M_UNLIKELY
#else
/* For normal builds, empty macros which does nothing */
#define START_COVERAGE
#define END_COVERAGE
#endif
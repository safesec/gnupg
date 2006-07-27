/* exechelp.h - Definitions for the fork and exec helpers
 *	Copyright (C) 2004 Free Software Foundation, Inc.
 *
 * This file is part of GnuPG.
 *
 * GnuPG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GnuPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 */

#ifndef GNUPG_COMMON_EXECHELP_H
#define GNUPG_COMMON_EXECHELP_H



/* Fork and exec the PGMNAME, connect the file descriptor of INFILE to
   stdin, write the output to OUTFILE, return a new stream in
   STATUSFILE for stderr and the pid of the process in PID. The
   arguments for the process are expected in the NULL terminated array
   ARGV.  The program name itself should not be included there.  if
   PREEXEC is not NULL, that function will be called right before the
   exec.  Returns 0 on success or an error code. */
gpg_error_t gnupg_spawn_process (const char *pgmname, const char *argv[],
                                 FILE *infile, FILE *outfile,
                                 void (*preexec)(void),
                                 FILE **statusfile, pid_t *pid);

/* Wait for the process identified by PID to terminate. PGMNAME should
   be the same as suplieed to the spawn fucntion and is only used for
   diagnostics. Returns 0 if the process succeded, GPG_ERR_GENERAL for
   any failures of the spawned program or other error codes.*/
gpg_error_t gnupg_wait_process (const char *pgmname, pid_t pid);


#endif /*GNUPG_COMMON_EXECHELP_H*/
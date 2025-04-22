#include <stdio.h>
/*
FSEEKLINE(3)                  Programmer's Manual                 FSEEKLINE(3)

NAME
       fseekline -- reposition a file-position indicator in a stream

SYNOPSIS
       #include <avs.h>

       int fseekline(FILE *fp, long offset, int whence);

DESCRIPTION
       fseekline() shall advance the cursor to one character after the newline
	   specified by offset.  SEEK_SET shall seek from  the  beginning  of  the
	   file, SEEK_CUR shall seek from the cursor, and SEEK_END shall  seek  in
	   reverse from the end of the file. The behavior when  using  a  negative
	   value for offset is undefined.

RETURN VALUE
       0  if  it  succeeds,  otherwise it shall return -1  and  set  errno  to
	   indicate the error.

ERRORS
       The fseekline() function shall fail under the same conditions as fseek.

SEE ALSO
       fseek(3p), stdio.h(0p)

Avery Terrel                         2025                         FSEEKLINE(3)
*/
int fseekline(FILE* fp, long offset, int whence);

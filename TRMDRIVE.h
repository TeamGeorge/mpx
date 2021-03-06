/***********************************************************
	MPX: The MultiProgramming eXecutive
	Project to Accompany
	A Practical Approach to Operating Systems
	Malcolm G. Lane & James D. Mooney
	Copyright 1993, P.W.S. Kent Publishing Co., Boston, MA.
	
	File Name: trmdrive.h

	Authors: M.G. Lane, J. Mooney
	Version: 2.1b
	Date: 11/10/93

	Purpose: Terminal Driver (Header file)

	Environments: IBM-PC, TURBO-C.
		



***********************************************************
  Change Log:

	12/01/92  jdm	separated from prtdrive.c
	12/08/92  jdm	removed hand;er declaration
	12/11/92  jdm	converted to trmdrive.c
	03/19/93  jdm	final version for V2.0b
        11/10/93  jdm	updated for large model

***********************************************************/

/* device error codes */

#define	ERR_TRM_OP_INVEFP	(-101)
#define	ERR_TRM_OP_ALROPN	(-102)
#define ERR_TRM_OP_OPFAIL	(-103)

#define	ERR_TRM_CL_NOTOPN	(-201)
#define ERR_TRM_CL_CLFAIL	(-202)

#define	ERR_TRM_RD_NOTOPN	(-301)
#define ERR_TRM_RD_INVBUF	(-302)
#define	ERR_TRM_RD_INVCNT	(-303)
#define	ERR_TRM_RD_DVBUSY	(-304)

#define	ERR_TRM_WR_NOTOPN	(-401)
#define ERR_TRM_WR_INVBUF	(-402)
#define	ERR_TRM_WR_INVCNT	(-403)
#define	ERR_TRM_WR_DVBUSY	(-404)

#define ERR_TRM_XY_INVPOS	(-601)

/* driver function prototypes */

/* trm_open: open the terminal */
/*	RETURNS: error code, or zero if ok */
int trm_open (int *ef_p	/* ptr to event flag */
	);

/* trm_close: close the terminal */
/*	RETURNS: error code, or zero if ok */
int trm_close (void);

/* trm_read: begin block keyboard input */
/*	RETURNS: error code, or zero if ok */
int trm_read (char *buf_p, /* ptr to buffer */
		int *count_p /* ptr to count value */
	);

/* trm_getc: process keyboard characters */
void trm_getc (void);


/* trm_write: perform block screen output */
/*	RETURNS: error code, or zero if ok */
int trm_write (char *buf_p, /* ptr to buffer */
		int *count_p /* ptr to count value */
	);

/* trm_clear: clear the screen */
/*	RETURNS: error code, or zero if ok */
int trm_clear (void);

/* trm_gotoxy: go to specified position */
/*	RETURNS: error code, or zero if ok */
int trm_gotoxy (int xpos, /* horizontal position: 0 - 79 */
		int ypos  /* vertical position: 0 - 23 */
	);

/* END OF FILE */

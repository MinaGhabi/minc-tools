/* ----------------------------- MNI Header -----------------------------------
@NAME       : message.h
@DESCRIPTION: Header file for acr-nema message code
@METHOD     : 
@GLOBALS    : 
@CREATED    : November 16, 1993 (Peter Neelin)
@MODIFIED   : $Log: message.h,v $
@MODIFIED   : Revision 1.1  1993-11-19 12:50:37  neelin
@MODIFIED   : Initial revision
@MODIFIED   :
@COPYRIGHT  :
              Copyright 1993 Peter Neelin, McConnell Brain Imaging Centre, 
              Montreal Neurological Institute, McGill University.
              Permission to use, copy, modify, and distribute this
              software and its documentation for any purpose and without
              fee is hereby granted, provided that the above copyright
              notice appear in all copies.  The author and McGill University
              make no representations about the suitability of this
              software for any purpose.  It is provided "as is" without
              express or implied warranty.
---------------------------------------------------------------------------- */

/* Group type */
typedef struct Acr_Message {
   int ngroups;
   long total_length;
   long message_length_offset;
   Acr_Element message_length_element;
   Acr_Group list_head;
   Acr_Group list_tail;
} *Acr_Message;

/* Message length group and element id */
#define ACR_GID_MESSLEN 0
#define ACR_EID_MESSLEN 1

/* Functions */
public Acr_Message acr_create_message(void);
public void acr_delete_message(Acr_Message message);
public void acr_message_add_group(Acr_Message message, Acr_Group group);
public Acr_Group acr_get_message_group_list(Acr_Message message);
public long acr_get_message_total_length(Acr_Message message);
public int acr_get_message_ngroups(Acr_Message message);
public Acr_Status acr_input_message(Acr_File *afp, Acr_Message *message);
public Acr_Status acr_output_message(Acr_File *afp, Acr_Message message);
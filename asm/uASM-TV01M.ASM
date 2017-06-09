;
; +========================================================================+
; |                                                                        |
; |     ASSEMBLY LANGUAGE PROGRAM FOR uASM 80x86 (INTEL-BASED) Assembler   |
; |                                                                        |
; +========================================================================+
;
;---------------------------------------------------------------------------
; * FILE NAME:    uASM-TV01M.ASM
; * PROGRAM NAME: uTV01
; * FUNCTION:     This file is intended to be one example of testing and
;                 verifying the functionality uASM assembler.
; * VERSION:      1.00
; * HISTORY:      (1) Creation -     2017/05/11
;                 (2) Modification - 2017/06/04
; * Notes:
;   (A) This file contains an assembly program which is a main program
;       and which is based on MS Macro Assembler.
;   (B) The program should be assembled correctly with minor modification
;       (change the directives IDENT and BSS)
;   (C) The program, after being assembled, should be able to be linked
;       with needed subroutines to run for testing and validation.
;   (D) For more details, please refer to the comments in the program.         
;
;---------------------------------------------------------------------------
;
           IDENT   uTV01M           ; This directive is not defined in MASM
                                    ; IDENT directive means IDENTification
                                    ; It is used to declare the program name
; The following 1 line is intentionally left empty                     

;
;---------------------------------------------------------------------------
; DEFINITIONs OF SYMBOLS
;---------------------------------------------------------------------------
;
  BEL      EQU     07H              ; ASCII Code of BEL (Alarming bell)
  BS       EQU     08H              ; ASCII Code of BS  (Backspace)
  CR       EQU     0DH              ; ASCII Code of CR  (Carriage Return)
  LF       EQU     0AH              ; ASCII Code of LF  (Line Feed)
;
.MODEL SMALL
           EXTERN  getDgt:NEAR
           EXTERN  putChr:NEAR
           EXTERN  NewLine:NEAR
           EXTERN  doComp:NEAR
.STACK  200H
;
;----- /// START OF DATA SEGMENT /// ---------------------------------------
;
.DATA                               ; The Data segment
   Start1  DB   "%% Hello, World! Execution starts....", BEL, CR, LF, '$'
   size1   DW   $-start1
   Goodbye DB   "%% Program stops. Exit now!",           BEL, CR, LF, '$'
   size2   DW   $-Goodbye
;
   uMSG    DB   CR, LF, "   Sum(1 .. "
   uIdgt   BSS  1                   ; 1-Byte buffer to store input value
           DB   ") = "
   uRval   BSS  2                   ; 2-Byte buffer to store result
           DB   CR, LF, '$'
;
;----- /// END OF DATA SEGMENT /// -----------------------------------------
;
;===== /// START OF CODE SEGMENT /// =======================================
.CODE
;
   MAIN    PROC
   ;------------------------------------------------------------------------
   ;       PROLOGUE
   ;------------------------------------------------------------------------
   ;
           MOV    AX, @DATA	    ; Set up DATA SEGMENT
           MOV    DS, AX
   ; Show message Start1
           LEA    DX, Start1	    ; Display program start message
           MOV    AH, 09H
           INT    21H
   ;
   mStart: CALL   NewLine
           Call   getDgt
           MOV    uIdgt, DL
           MOV    DL, AL
           CALL   doComp
           XCHG   AH, AL
           MOV    uRval, AX
           LEA    DX, uMSG	    ; Display result message
           MOV    AH, 09H
           INT    21H
   mEnd:
           CALL   NewLine
   ;
   ;------------------------------------------------------------------------
   ;       EPILOGUE
   ;------------------------------------------------------------------------
   ;
   ;       Program exit
           LEA    DX, Goodbye       ; Display goodbye message
           MOV    AH, 09H
           INT    21H
           MOV    AX,4C00H          ; Program exits using DOS service
           INT    21H
   ;
   MAIN    ENDP
;
;===== /// END OF CODE SEGMENT /// =========================================
;
   END  MAIN
; +------------------------------------------------------------------------+
; |     END OF THIS PROGRAM FILE                                           I
; +------------------------------------------------------------------------+
;
;===========================================================================
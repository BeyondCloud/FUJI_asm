;
; +========================================================================+
; |                                                                        |
; |     ASSEMBLY LANGUAGE PROGRAM FOR uASM 80x86 (INTEL-BASED) Assembler   |
; |                                                                        |
; +========================================================================+
;
;---------------------------------------------------------------------------
; * FILE NAME:    uASM-TV01S.ASM
; * PROGRAM NAME: uTV01
; * FUNCTION:     This file is intended to be one example of testing and
;                 verifying the functionality uASM assembler.
; * VERSION:      1.00
; * HISTORY:      (1) Creation -     2017/05/11
;                 (2) Modification - 2017/06/04
; * Notes:
;   (A) This file contains a number of subroutines in assembly language
;       which are based on MS Macro Assembler and should be assembled
;       correctly with minor modification.
;   (B) Th program in this file can be used for Intel 80x86 processor in
;       16-bit mode and linked with a main program to run.
;   (C) For more details, please refer to the comments in the program.         
;
;---------------------------------------------------------------------------
;
;           IDENT   uTV01S           ; This directive is not defined in MASM
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
           PUBLIC  getDgt
           PUBLIC  putChr
           PUBLIC  NewLine
           PUBLIC  doComp
;
;----- /// START OF DATA SEGMENT /// ---------------------------------------
;

;
;----- /// END OF DATA SEGMENT /// -----------------------------------------
;
;===== /// START OF CODE SEGMENT /// =======================================
.CODE
;
   getDgt  PROC                     ; Subroutine to get a decimal digit
                                    ; and convert to binary
   gLoop:  MOV    DL, '?'
           CALL   putChr
           MOV    AH, 01H           ; Get user input with echo
           INT    21H
           CMP    AL, '0'           ; Check for invalid input
           JLE    gError
           CMP    AL, '9'
           JG     gError
           MOV    DL, AL
           SUB    AL, 48            ; Convert ASCII to decimal binary
           RET
   gError:
           MOV    DL, BEL           ; Error alert
           CALL   putChr 
           JMP    gLoop
   getDgt  ENDP                     ; End of Subroutine
;
   putChr  PROC                     ; Subroutine to display a character
                                    ; at call register DL carries the
           CMP    DL, 0             ; character to be displayed
           JE     NoMore            ; DL = 00 means end-of-string
           MOV    AH, 02H
           INT    21H
   NoMore: 
           RET
   putChr  ENDP                     ; End of Subroutine
;
   NewLine PROC                     ; Subroutine to start a new line
           MOV    DL, CR
           CALL   putChr
           MOV    DL, LF
           CALL   putChr
           RET
   NewLine ENDP                     ; End of Subroutine
;
   doComp  PROC                     ; Subroutine to compute Sum of 1 .. n
           MOV    AX, 0             ; at call register DL carries n
           MOV    DH, 0
   doLoop: CMP    DX, 0
           JLE    doDone
           ADD    AX, DX
           DEC    DX
           JMP    doLoop
   doDone:                          ; Result is in AX (Two ASCII Chars)
           DB     0D4H              ; Define the AAM instruction
           DB     00AH
           ADD    AX, 3030H         ; Convert decimal binary to ASCII           
           RET
   doComp  ENDP                     ; End of Subroutine
;
;===== /// END OF CODE SEGMENT /// =========================================
;
   END
; +------------------------------------------------------------------------+
; |     END OF THIS PROGRAM FILE                                           I
; +------------------------------------------------------------------------+
;
;===========================================================================
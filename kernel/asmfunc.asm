; asmfunc.asm
;
; System V AMD64 Calling Convention
; Registers: RDI, RSI, RDX, R8, R9

bits 64
section .text

global IoOut32    ; void IoOut32(uint16_t addr, uint32_t data);
IoOut32:
  mov dx, di      ; dx = addr
  mov eax, esi    ; eax = data
  out dx, eax     ; special command `out` to write data into IO port address.
  ret

global IoIn32     ; uint32_t IoIn32(uint16_t addr);
IoIn32:
  mov dx, di      ; dx = addr
  mov dx, di      ; special command `in` to write data into IO port address.
  ret

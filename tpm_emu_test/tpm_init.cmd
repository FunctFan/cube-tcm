#first command
80 01 00 00 00 0A 00 00 01 81 

00 C1 00 00 00 0A 00 00 00 F1 
#TPM_ORD_GetTicks

00 C1 00 00 00 0C 00 00 00 99 00 01  
#TPM_ORD_Startup

00 C1 00 00 00 0A 00 00 00 50 
#TPM_ORD_SelfTestFull
 
00 C1 00 00 00 0A 40 00 00 0B 
#TSC_ORD_ResetEstablishmentBit

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <dlfcn.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>


#include "data_type.h"
#include "alloc.h"
#include "memfunc.h"
#include "basefunc.h"
#include "struct_deal.h"
#include "crypto_func.h"
#include "channel.h"
#include "memdb.h"
#include "message.h"
#include "connector.h"
#include "ex_module.h"
#include "tcm_constants.h"
#include "app_struct.h"
#include "pik_struct.h"
#include "sm4.h"
#include "tcmfunc.h"
#include "vtcm_alg.h"

int main(int argc,char **argv)
{

    int ret;
   
    UINT32 handle;
    int PcrLength;
    BYTE * PcrValue;
    BYTE Buf[DIGEST_SIZE*64];
    int  Buflen;
    UINT32 authHandle;
    UINT32 KeyHandle;
    UINT32 keyAuthHandle;

    BYTE inDigest[DIGEST_SIZE];
    BYTE outDigest[DIGEST_SIZE];

    ret=_TSMD_Init();

    ret= TCM_LibInit(); 

//   ret= TCM_CreateEndorsementKeyPair(Buf,&Buflen); 

    Memset(inDigest,'A',DIGEST_SIZE);

    vtcm_ex_sm3(outDigest,1,inDigest,32);
    calculate_context_sm3(inDigest,32,outDigest);

    ret=TCM_Extend(0,inDigest,outDigest);

    if(ret==0)
    	ret=TCM_PcrRead(0,outDigest);

    TCM_PUBKEY pubek;

    ret=TCM_ReadPubek(&pubek);

    ret=TCM_APCreate(04, NULL, "sss", &authHandle);
    printf("authHandle is : %x\n",authHandle);
    return ret;	

}


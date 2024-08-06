#include <Windows.h>

int main(){
    HKEY hKeyV;
    LONG resultv;

    char data[255];
    DWORD dataSize = sizeof(data);
    
    const char* pathvbox = "SYSTEM\\CurrentControlSet\\Services\\VBoxGuest";
    resultv = RegOpenKeyExA(HKEY_LOCAL_MACHINE, pathvbox, 0, KEY_READ, &hKeyV);

    RegGetValueA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\BIOS", "BaseBoardManufacturer", RRF_RT_REG_SZ, NULL, (PVOID)&data, &dataSize);

    if(resultv == ERROR_SUCCESS || strcmp(data, "Microsoft Corporation") == 0){
        MessageBox(NULL, "VM found", "Inside of VM or Sandbox", MB_OK);
    }

    else {
        MessageBox(NULL, "NO VM", "NO VM", MB_OK);
    }
    return 0;
}
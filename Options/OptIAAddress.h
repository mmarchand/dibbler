/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
 */

#ifndef OPTIAADDRESS_H
#define OPTIAADDRESS_H

#include "SmartPtr.h"
#include "Container.h"
#include "Opt.h"
#include "IPv6Addr.h"

class TOptIAAddress : public TOpt
{
  public:
    TOptIAAddress(char* &addr, int& n, TMsg* parent);
    TOptIAAddress( SPtr<TIPv6Addr> addr, unsigned long pref, unsigned long valid, TMsg* parent);
    int getSize();
    
    char * storeSelf( char* buf);
    SPtr<TIPv6Addr> getAddr();
    unsigned long getPref();
    unsigned long getValid();
    void setPref(unsigned long pref);
    void setValid(unsigned long valid);
    bool isValid();

    virtual bool doDuties() { return true; } // does nothing on its own
 private:
    SPtr<TIPv6Addr> Addr;
    unsigned long Valid;
    unsigned long Pref;
    bool ValidOpt;
};

#endif

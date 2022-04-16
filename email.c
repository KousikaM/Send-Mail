#include "stdafx.h"
#include <tchar.h>
#include <Windows.h>

#include "EASendMailObj.tlh"
using namespace EASendMailObjLib;

const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

int _tmain(int argc, _TCHAR* argv[])
{
    ::CoInitialize(NULL);

    IMailPtr oSmtp = NULL;
    oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
    oSmtp->LicenseCode = _T("TryIt");

    // Set your gmail email address
    oSmtp->FromAddr = _T("gmailid@gmail.com");
    // Add recipient email address
    oSmtp->AddRecipientEx(_T("support@emailarchitect.net"), 0);

    // Set email subject
    oSmtp->Subject = _T("simple email from Visual C++ with gmail account");
    // Set email body
    oSmtp->BodyText = _T("this is a test email sent from Visual C++ project with Gmail");

    // Gmail SMTP server address
    oSmtp->ServerAddr = _T("smtp.gmail.com");

    // Gmail user authentication should use your
    // Gmail email address as the user name.
    // For example: your email is "gmailid@gmail.com", then the user should be "gmailid@gmail.com"
    oSmtp->UserName = _T("gmailid@gmail.com");
    oSmtp->Password = _T("yourpassword");

    // Use SSL 465 port,
    oSmtp->ServerPort = 465;

    // detect SSL/TLS automatically
    oSmtp->ConnectType = ConnectSSLAuto;

    _tprintf(_T("Start to send email via gmail account ...\r\n"));

    if(oSmtp->SendMail() == 0)
    {
        _tprintf(_T("email was sent successfully!\r\n"));
    }
    else
    {
        _tprintf(_T("failed to send email with the following error: %s\r\n"),
            (const TCHAR*)oSmtp->GetLastErrDescription());
    }

    return 0;
}

# Steps to build this sample

- Below are the two projects used to build this sample
  
  1.  *Client - ComClientSample\ComClientSample.csproj* (.Net Client to invoke the packaged COM server deployed as MSIX package)
  
  2. *Com Server - MFCComServerDlgBGColor\MFCComServerBGColorTest.vcxproj* (MFC dialog based ATL COM Server)

- The folder *MSIXPackageFiles_COMServer* conatins the files needed to build MSIX COM Server package. This folder contains AppxManifest.xml and other required resources to build the MSIX package. The COM server binaries (.exe and .tlb files) built from the sample project should be copied here.
  

- Below commands are used to build and sign the MSIX package
  
  *"C:\Program Files (x86)\Windows Kits\10\bin\10.0.20348.0\x64\MakeAppx.exe" pack /v /h SHA256 /d MSIXPackageFiles_COMServer /p MFCComServerDlgBGColor.msix*
  
  *"C:\Program Files (x86)\Windows Kits\10\bin\10.0.20348.0\x64\SignTool.exe" sign /fd SHA256 /a /f "C:\AcressoTestCA.pfx" /p <Password> MFCComServerDlgBGColor.msix*
  
- Deploy the MSIX pckage and use the client application to connect to the COM Server application  



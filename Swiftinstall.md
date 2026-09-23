# Windows 使用 winget 安装 swiftc（Swift编译器）

通过Windows包管理器（也称为WinGet）安装Swift。
然后安装Swift和其他依赖：

```powershell
winget install --id Microsoft.VisualStudio.2022.Community --exact --force --custom "--add
Microsoft.VisualStudio.Component.Windows11SDK.22621 --add 
Microsoft.VisualStudio.Component.VC.Tools.x86.x64 --add
Microsoft.VisualStudio.Component.VC.Tools.ARM64" --source winget

winget install --id Swift.Toolchain -e --source winget

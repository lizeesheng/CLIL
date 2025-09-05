# CLI Launcher README
![](https://lizeesheng.github.io/pic-down/svg.svg)

![Github stars](https://img.shields.io/github/stars/lizeesheng/CLIL.svg)

## Disclaimer
This is not an official project from Mojang Studios or Microsoft.

This project uses [aria2](https://github.com/aria2/aria2) for downloading, and [7zip](https://7-zip.org/) for file extraction, and nlohmann json for json file reading and anazlying.

## Features
- You can launch Minecraft with a single simple command in Windows command-line environments (e.g., cmd, PowerShell, etc.).
- The launcher will output logs in the console (log output can be disabled).
- Notably, if you only start the program, you can set up and launch your game by following the on-screen prompts.


## Compilation

In the project directory, execute the following commands (ensure MinGW GCC is installed and fully supports C++ 11):
```bash
g++ -Ofast -Wl,--stack=16777216 -std=c++17 java_downloader.cpp -o jdr.exe
g++ -Ofast -Wl,--stack=16777216 -std=c++17 launcher_main.cpp -o clil.exe
```

## Usage

### Binary Files

`jdr.exe`: Java Downloader, invoked when the main program fails to detect JDK.

`clil.exe`: Main program.

### Parameters

#### `clil.exe`

`-cm` Sets the download source of Alibaba Dragonwell JDK.Using this parameter means you are in China mainland.

`-v [GAME_VERSION]`	Specifies the version of Minecraft to launch. Must be a valid version present in version_manifest.json.

`-dl`	Disables log output in the console.

`-m [MEM_SIZE]`	Sets the maximum memory allocated to the JVM. Defaults to 512MB if not specified. Unit: `KB` .

`-a [ARGC]`	Adds additional JVM parameters.

`-un [USERNAME]`	Specifies the in-game username. If not provided, a random name from Player000 to Player999 will be used.

## Notes

Official account authentication is not supported at this time.
Before version v1.1, only vanilla Minecraft versions are supported for download; modpacks and custom modded versions are not supported.

## 声明

这不是一个来自 Mojang Studios 或 Microsoft 的官方项目。

本项目使用 [aria2](https://github.com/aria2/aria2) 下载，

[7zip](https://7-zip.org/) 解压缩，

nlomann json 读取、分析文件。

## 功能

- 你可以用一句简单的命令在 Windows 命令行环境（如 cmd, PowerShell 等）启动我的世界，
- 然后启动器会在控制台中输出日志（可关闭）。
- 特殊的，如果你仅仅启动了程序，你可以根据提示设置并启动你的游戏。

## 编译

在项目目录下执行（已安装 MinGW GCC 并完全支持 C++ 11 ）：
```bash
g++ -Ofast -Wl,--stack=16777216 -std=c++17 java_downloader.cpp -o jdr.exe
g++ -Ofast -Wl,--stack=16777216 -std=c++17 launcher_main.cpp -o clil.exe
```

## 用法

### 二进制文件

`jdr.exe` Java下载器，在主程序未检测到 JDK 时调用。

`clil.exe` 主程序。

### 参数

#### `clil.exe`

`-cm` 设置 Alibaba Dragonwell JDK 下载源。使用此参数意味着您在中国大陆。

`-v [GAME_VERSION]` 启动游戏的版本，需要真实存在并位于 [version_manifest.json](https://piston-meta.mojang.com/mc/game/version_manifest.json) 中。

`-dl` 关闭日志输出。

`-m [MEM_SIZE]` 设置 JVM 最大内存。不指定默认为 512MB ， 单位为 `KB` 。

`-a [ARGC]` 额外 JVM 参数。

`-un [USERNAME]` 用户名，不指定为 Player000 ~ Player999 之中一个。


## 注意

暂不支持正版验证，在 `v1.1` 前只支持原版的下载，不支持模组与整合版的下载。

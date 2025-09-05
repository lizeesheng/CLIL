/*
CLI Launcher Java Downloader
Pulished by GPLv3
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <filesystem>
const int threadNum = 256;
std::string ProgramPath;
const std::unordered_map<int, std::pair<std::string, std::pair<std::string, std::string> > > jdkURLs = {
	{8, {"Alibaba_Dragonwell_Standard_8.25.24_x64_windows.zip", {"https://dragonwell.oss-cn-shanghai.aliyuncs.com/8.25.24/Alibaba_Dragonwell_Standard_8.25.24_x64_windows.zip", "https://github.com/dragonwell-project/dragonwell8/releases/download/dragonwell-standard-8.25.24_jdk8u452-ga/Alibaba_Dragonwell_Standard_8.25.24_x64_windows.zip"}}},
	{11, {"Alibaba_Dragonwell_Standard_11.0.27.23.6_x64_windows.zip", {"https://github.com/dragonwell-project/dragonwell11/releases/download/dragonwell-standard-11.0.27.23_jdk-11.0.27-ga/Alibaba_Dragonwell_Standard_11.0.27.23.6_x64_windows.zip", "https://github.com/dragonwell-project/dragonwell11/releases/download/dragonwell-standard-11.0.27.23_jdk-11.0.27-ga/Alibaba_Dragonwell_Standard_11.0.27.23.6_x64_windows.zip"}}},
	{17, {"Alibaba_Dragonwell_Standard_17.0.15.0.16.6_x64_windows.zip", {"https://dragonwell.oss-cn-shanghai.aliyuncs.com/17.0.15.0.16%2B6/Alibaba_Dragonwell_Standard_17.0.15.0.16.6_x64_windows.zip", "https://github.com/dragonwell-project/dragonwell17/releases/download/dragonwell-standard-17.0.15.0.16%2B6_jdk-17.0.15-ga/Alibaba_Dragonwell_Standard_17.0.15.0.16.6_x64_windows.zip"}}},
	{21, {"Alibaba_Dragonwell_Standard_21.0.7.0.7.6_x64_windows.zip", {"https://dragonwell.oss-cn-shanghai.aliyuncs.com/21.0.7.0.7%2B6/Alibaba_Dragonwell_Standard_21.0.7.0.7.6_x64_windows.zip", "https://github.com/dragonwell-project/dragonwell21/releases/download/dragonwell-standard-21.0.7.0.7%2B6_jdk-21.0.7-ga/Alibaba_Dragonwell_Standard_21.0.7.0.7.6_x64_windows.zip"}}}
};
bool isInChinaMainland = false;
void run7zCmd(std::string filename, std::string path) {
	system(("7z x " + filename + " -aoa -o" + ProgramPath + path).c_str());
}
void runAria2Cmd(std::string url) {
	system(("aria2c --allow-overwrite=true " + url).c_str());
}
void delFile(std::string filename) {
	system(("del " + filename).c_str());
}
void javaDownload(int ver) {
	switch (ver) {
		case 8:
			runAria2Cmd((isInChinaMainland ? jdkURLs.at(ver).second.first : jdkURLs.at(ver).second.second));
			run7zCmd(jdkURLs.at(ver).first, ".jdk");
			break;
		case 11:
			runAria2Cmd((isInChinaMainland ? jdkURLs.at(ver).second.first : jdkURLs.at(ver).second.second));
			run7zCmd(jdkURLs.at(ver).first, ".jdk");
			break;
		case 17:
			runAria2Cmd((isInChinaMainland ? jdkURLs.at(ver).second.first : jdkURLs.at(ver).second.second));
			run7zCmd(jdkURLs.at(ver).first, ".jdk");
			break;
		case 21:
			runAria2Cmd((isInChinaMainland ? jdkURLs.at(ver).second.first : jdkURLs.at(ver).second.second));
			run7zCmd(jdkURLs.at(ver).first, ".jdk");
			break;
	}
	delFile(jdkURLs.at(ver).first);
}
int tenpow(int x) {
	int rt = 1;
	if (x < 0) {
		return 0;
	}
	if (x == 0) {
		return rt;
	}
	while (x--) {
		rt *= 10;
	}
	return rt;
}
int main(int argc, char* argv[]) {
	ProgramPath = std::filesystem::current_path().string();
	ProgramPath.push_back('\\');
	if (argv[2] == std::string("-cm")) {
		isInChinaMainland = true;
	}
	int version = std::__cxx11::stoi(argv[1]);
	std::cout << "jdr.exe : Java Downloader of CLIL Project.\n"
	          << "JDK is from Alibaba Dragonwell.\n"
	          << "Download Version:" << version << "\n";
	javaDownload(version);
	return 0;
}

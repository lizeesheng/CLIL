#include <bits/stdc++.h>
#include "nlohmann/json.hpp"
using namespace std;
typedef nlohmann::json Json;
Json versionManifest;
Json versionJson;
Json versionAssetsIndex;
string version;
string extraJVMArgv;
string userName;
string mainProgramPath = filesystem::current_path().string();
int javaVersion;
int memSize = 512;
bool isArgvEmpty = false;
bool isUserInChinaMainland = false;
bool isLoggingOnCMD = true;
struct versionDesc{
	string id;
	string url;
	string type;
	string timee;
	string rtime;
};
vector<versionDesc> versionManifestAnalzyed;
bool checkExists(const std::string& path) {
	return std::filesystem::exists(path);
}
void analzyeCommandLine(int argc,char ** argv){
	if(argc == 1){
		isArgvEmpty = true;
		return;
	}
	for(int i = 1;i < argc;i++){
		string argvtmp = argv[i];
		if(argvtmp == "-cm"){
			isUserInChinaMainland = true;
		} else if(argvtmp == "-v" && i != argc-1){
			if(argv[i+1][0] == '-'){
				cout << "Wrong argument \"-v\".\n";
				exit(1);
			}
			version = argv[i+1];
			i++;
		} else if(argvtmp == "-dl"){
			isLoggingOnCMD = false;
		} else if(argvtmp == "-m" && i != argc-1){
			if(argv[i+1][0] == '-'){
				cout << "Wrong argument \"-m\".\n";
				exit(1);
			}
			memSize = stoi(argv[i+1]);
			i++;
		} else if(argvtmp == "-a" && i != argc-1){
			if(argv[i+1][0] == '-'){
				cout << "Wrong argument \"-a\".\n";
				exit(1);
			}
			extraJVMArgv = argv[i+1];
			i++;
		} else if(argvtmp == "-un" && i != argc-1){
			if(argv[i+1][0] == '-'){
				cout << "Wrong argument \"-a\".\n";
				exit(1);
			}
			userName = argv[i+1][0];
			i++;
		} else {
			cout << "Unknown argument \""+argvtmp+"\"\n";
			exit(1);
		}
	}
}
void runAria2Cmd(string url,string path){
	system(("aria2c --split=256 "+url+" --dir "+mainProgramPath+"\\"+path).c_str());
}
void run7zCmd(string filename,string path){
	system(("7z x "+filename+" -aoa -o"+mainProgramPath+"\\"+path).c_str());
}
void downloadVersionManifest(){
	runAria2Cmd("https://piston-meta.mojang.com/mc/game/version_manifest.json",".minecraft\\versions\\");
	ifstream in(mainProgramPath+"\\.minecraft\\versions\\version_manifest.json");
	in >> versionManifest ;
	in.close();
	for(auto& item : versionManifest["versions"]){
		versionDesc vd;
		vd.id=item["id"];
		vd.url=item["url"];
		vd.timee=item["time"];
		vd.rtime=item["releaseTime"];
		vd.type=item["type"];
		versionManifestAnalzyed.push_back(vd);
	}
}
void downloadVersionJson(){
	for(int i=0;i<versionManifestAnalzyed.size();i++){
		if(versionManifestAnalzyed[i].id == version){
			versionDesc tmp = versionManifestAnalzyed[i];
			runAria2Cmd(tmp.url,".minecraft\\versions\\"+version+"\\");
			ifstream in(mainProgramPath+"\\.minecraft\\versions\\"+version+"\\"+version+".json");
			in >> versionJson ;
			in.close();
			return;
		}
	}
	cout<<"Version Not Found\n";
	exit(1);
}
void completeFiles(){
	runAria2Cmd(versionJson["assetIndex"]["url"],".minecraft\\assets\\indexes");
	ifstream in(mainProgramPath+"\\.minecraft\\assets\\indexes\\"+versionJson["assetIndex"]["id"].get<string>()+".json");
	in >> versionAssetsIndex;
	in.close();
	javaVersion = versionJson["javaVersion"]["majorVersion"].get<int>();
	if(javaVersion == 16){
		javaVersion++;
	}
	runAria2Cmd(versionJson["downloads"]["client"]["url"],".minecraft\\versions\\"+version);
	
}
void launchGame(){
	downloadVersionManifest();
	downloadVersionJson();
	completeFiles();
}
void tipsForSetting(){
	if(isArgvEmpty){
		cout<<"Welcome to use CLIL!\n";
		cout<<"Player Name:";
		cin>>userName;
		cout<<"Memory Size (Unit: MB):";
		cin>>memSize;
		cout<<"Version:";
		cin>>version;
		cout<<"Extra JVM arguments (input \"none\" to skip it):";
		cin>>extraJVMArgv;
		if(extraJVMArgv=="none"){
			extraJVMArgv.clear();
		}
		cout<<"Close logging(y or n)?:";
		string tmp;
		cin>>tmp;
		if(tmp=="y"){
			isLoggingOnCMD = false;
		}
	}
}
int main(int argc,char* argv[]){
	analzyeCommandLine(argc,argv);
	tipsForSetting();
	launchGame();
	return 0;
}

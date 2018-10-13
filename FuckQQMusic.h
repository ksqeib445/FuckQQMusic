#pragma once
#include <iostream>
#include <string>

using namespace std;
class FuckQQMusic
{
public:
	FuckQQMusic();
	virtual ~FuckQQMusic();
	int printmenu(void); //输出菜单
	void clear(void); //用于清屏
	void fucksonglink(string); //用于解析单曲
	string getonweb(string); //用于从api拉取json
	string indata; //用于接受输入
private:
	string mid; //歌曲id
	string title; //歌曲标题
	string album; //歌曲专辑
	string author; //歌曲作者
	string url; //图片url
	string lrc; //歌词url
};
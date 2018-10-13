#include <iostream>
#include <curl/curl.h>
#include "FuckQQMusic.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace std;
using namespace rapidjson;

FuckQQMusic::FuckQQMusic()
{
}


FuckQQMusic::~FuckQQMusic()
{
}

static int writer(char *data, size_t size, size_t nmemb, string *writerData)//
{
	unsigned long sizes = size * nmemb;
	writerData->append(data, sizes);
	return sizes;
}


void FuckQQMusic::clear(void)
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

int FuckQQMusic::printmenu(void)
{
	FuckQQMusic::clear();
	int xuanze = 0;
	cout << "#####################" << endl << endl;
	cout << "1.查找歌曲(未实现)" << endl;
	cout << "2.解析单曲" << endl;
	cout << "3.解析歌单(施工中)" << endl << endl;
	cout << "#####################" << endl;
	cout << "Powered By Kcass" << endl;
	cout << "请输入你的瓜皮选择" << endl;
	fflush(stdin);
	cin.clear();
	cin >> xuanze;
	return xuanze;
}

void FuckQQMusic::fucksonglink(string indata)
{
	string webjson = FuckQQMusic::getonweb("https://api.mlwei.com/music/api/?key=523077333&type=song&id=002obk1M1cqpjS");
	//string webjson = FuckQQMusic::getonweb("https://api.mlwei.com/music/api/?key=523077333&type=song&id=" + indata);
	const char* json = webjson.data();
	Document document;
	document.SetObject();
	document.Parse(json);
	mid = document["mid"].GetString();
	title = document["title"].GetString();
	album = document["album"].GetString();
	author = document["author"].GetString();
	url = document["url"].GetString();
	lrc = document["lrc"].GetString();
	cout << "id:" << mid << endl;
	cout << "标题:" <<title << endl;
	cout << "专辑:" << album << endl;
	cout << "作者:" << author << endl;
	cout << "URL:" << url << endl;
	cout << "歌词" << lrc << endl;
}

string FuckQQMusic::getonweb(string url)
{
	curl_global_init(CURL_GLOBAL_ALL);
	CURL *easy_handle = curl_easy_init();
	// 设置网址
	curl_easy_setopt(easy_handle, CURLOPT_URL, url.data());
	// 设置回调函数
	curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, writer);
	// 回调函数参数
	string data;
	curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &data);
	// 执行数据请求
	curl_easy_perform(easy_handle);
	// 释放资源
	curl_easy_cleanup(easy_handle);
	curl_global_cleanup();
	return data;
}
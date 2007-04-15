#pragma once
#include <string>
#include <vector>

#include "SVN.h"
#include "SerializeUtils.h"
#include "RWSection.h"

class CUrlInfo
{
public:
	CUrlInfo(void);
	~CUrlInfo(void);

	wstring						username;
	wstring						password;

	wstring						url;
	wstring						name;
	__time64_t					lastchecked;
	svn_revnum_t				lastcheckedrev;

	int							minutesinterval;
	bool						fetchdiffs;

	map<svn_revnum_t,SVNLogEntry> logentries;

	bool						Save(HANDLE hFile);
	bool						Load(HANDLE hFile);
};

class CUrlInfos
{
public:
	CUrlInfos(void);
	~CUrlInfos(void);

	void						Save();
	void						Load();
	void						Save(LPCWSTR filename);
	void						Load(LPCWSTR filename);
	bool						IsEmpty();

	const map<wstring,CUrlInfo> *	GetReadOnlyData();
	map<wstring,CUrlInfo> *		GetWriteData();
	void						ReleaseData();

protected:
	bool						Save(HANDLE hFile);
	bool						Load(HANDLE hFile);

private:
	map<wstring,CUrlInfo>		infos;
	CRWSection					guard;
};


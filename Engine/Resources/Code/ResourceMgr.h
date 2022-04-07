/*!
 * \file ResourceMgr.h
 * \date 2016/06/13 10:15
 *
 * \author Administrator
 * Contact: user@company.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/
#ifndef ResourceMgr_h__
#define ResourceMgr_h__

#include "Engine_Include.h"

BEGIN(Engine)

class CResources;
class CComponent;
class CGameObject;

class ENGINE_DLL CResourceMgr
{
public:
	DECLARE_SINGLETON(CResourceMgr)

private:
	CResourceMgr(void);
	~CResourceMgr(void);

public:
	CComponent* CloneResource(RESOURCETYPE eResourceType, const wstring& wstrResourceKey ,CGameObject* pGameObj); //CGameObject* pGameObj = 이 컴포넌트를 가지고 있는 게임오브젝트 포인터
	void GetVertexInfo(RESOURCETYPE eResourceType, const wstring& wstrResourceKey
		, void* pVertex);

public:
	void SetVertexInfo(RESOURCETYPE eResourceType, const wstring& wstrResourceKey
		, void* pVertex);

public:
	HRESULT AddBuffer(LPDIRECT3DDEVICE9 pDevice
		, RESOURCETYPE eResourceType
		, BUFFERTYPE eBufferType
		, const wstring& wstrResourceKey
		, const WORD& wCntX = 0, const WORD& wCntZ = 0, const WORD& wItv = 0);

	HRESULT AddTexture(LPDIRECT3DDEVICE9 pDevice
		, RESOURCETYPE eResourceType
		, TEXTURETYPE eTextureType
		, const wstring& wstrResourceKey
		, const wstring& wstrFilePath
		, const WORD& wCnt);

	void ResetDynamic(void);

private:
	void Release(void);

private:
	typedef map<wstring, CResources*>		MAPRESOURCE;
	MAPRESOURCE		m_mapResource[RESOURCE_END];
};

END

#endif // ResourceMgr_h__
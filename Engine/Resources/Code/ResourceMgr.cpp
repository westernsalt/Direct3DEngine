#include "ResourceMgr.h"
#include "TriColor.h"
#include "RcColor.h"
#include "Resources.h"
#include "Texture.h"
#include "RcTex.h"
#include "TerrainTex.h"
#include "CubeTex.h"
#include "CubeColor.h"

IMPLEMENT_SINGLETON(Engine::CResourceMgr)

Engine::CResourceMgr::CResourceMgr(void)
{

}

Engine::CResourceMgr::~CResourceMgr(void)
{
	Release();
}

void Engine::CResourceMgr::GetVertexInfo(RESOURCETYPE eResourceType
										 , const wstring& wstrResourceKey 
										 , void* pVertex)
{
	MAPRESOURCE::iterator iter = m_mapResource[eResourceType].find(wstrResourceKey);
	if(iter == m_mapResource[eResourceType].end())
	{
		TAGMSG_BOX(wstrResourceKey.c_str(), L"버퍼 얻기 실패");
		return;
	}
	((CVIBuffer*)iter->second)->GetVtxInfo(pVertex);
}

void Engine::CResourceMgr::SetVertexInfo(RESOURCETYPE eResourceType
										 , const wstring& wstrResourceKey 
										 , void* pVertex)
{
	MAPRESOURCE::iterator iter = m_mapResource[eResourceType].find(wstrResourceKey);
	if(iter == m_mapResource[eResourceType].end())
	{
		TAGMSG_BOX(wstrResourceKey.c_str(), L"버퍼 얻기 실패");
		return;
	}
	((CVIBuffer*)iter->second)->SetVtxInfo(pVertex);
}

HRESULT Engine::CResourceMgr::AddBuffer(LPDIRECT3DDEVICE9 pDevice 
										, RESOURCETYPE eResourceType 
										, BUFFERTYPE eBufferType 
										, const wstring& wstrResourceKey 
										, const WORD& wCntX /*= 0*/, const WORD& wCntZ /*= 0*/, const WORD& wItv /*= 0*/)
{
	MAPRESOURCE::iterator	iter = m_mapResource[eResourceType].find(wstrResourceKey);
	if(iter != m_mapResource[eResourceType].end())
	{
		TAGMSG_BOX(wstrResourceKey.c_str(), L"중복된 버퍼 추가");
		return E_FAIL;
	}

	CResources*	pResource = NULL;
	switch(eBufferType)
	{
	case BUFFER_TRICOLOR:
		pResource = CTriColor::Create(pDevice);
		break;

	case BUFFER_RCCOLOR:
		pResource = CRcColor::Create(pDevice);
		break;

	case BUFFER_RCTEX:
		pResource = CRcTex::Create(pDevice);
		break;

	case BUFFER_TERRAINTEX:
		pResource = CTerrainTex::Create(pDevice, wCntX, wCntZ, wItv);
		break;

	case BUFFER_CUBETEX:
		pResource = CCubeTex::Create(pDevice);
		break;

	case BUFFER_CUBECOLOR:
		pResource = CCubeColor::Create(pDevice);
		break;
	}
	NULL_CHECK_RETURN(pResource, E_FAIL);
	m_mapResource[eResourceType].insert(MAPRESOURCE::value_type(wstrResourceKey, pResource));
	return S_OK;
}

HRESULT Engine::CResourceMgr::AddTexture(LPDIRECT3DDEVICE9 pDevice 
										 , RESOURCETYPE eResourceType 
										 , TEXTURETYPE eTextureType 
										 , const wstring& wstrResourceKey 
										 , const wstring& wstrFilePath 
										 , const WORD& wCnt)
{
	MAPRESOURCE::iterator iter = m_mapResource[eResourceType].find(wstrResourceKey);
	if(iter != m_mapResource[eResourceType].end())
		return E_FAIL;

	CResources* pResource = CTexture::Create(pDevice, eTextureType, wstrFilePath, wCnt);
	NULL_CHECK_RETURN(pResource, E_FAIL);

	m_mapResource[eResourceType].insert(MAPRESOURCE::value_type(wstrResourceKey, pResource));
	return S_OK;
}

void Engine::CResourceMgr::ResetDynamic(void)
{
	for_each(m_mapResource[RESOURCE_DYNAMIC].begin(), m_mapResource[RESOURCE_DYNAMIC].end()
		, CDeleteMap());
	m_mapResource[RESOURCE_DYNAMIC].clear();
}

void Engine::CResourceMgr::Release(void)
{
	for(int i = 0; i < RESOURCE_END; ++i)
	{
		for_each(m_mapResource[i].begin(), m_mapResource[i].end()
			, CDeleteMap());
		m_mapResource[i].clear();
	}
}

Engine::CComponent* Engine::CResourceMgr::CloneResource(RESOURCETYPE eResourceType, const wstring& wstrResourceKey,Engine::CGameObject* pGameObj)
{
	MAPRESOURCE::iterator iter = m_mapResource[eResourceType].find(wstrResourceKey);
	if(iter == m_mapResource[eResourceType].end())
	{
		TAGMSG_BOX(wstrResourceKey.c_str(), L"리소스 복사 실패");
		return NULL;
	}
	return iter->second->CloneResource(pGameObj);
}
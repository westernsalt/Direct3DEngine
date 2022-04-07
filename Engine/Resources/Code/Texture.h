/*!
 * \file Texture.h
 * \date 2016/06/13 10:42
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

#ifndef Texture_h__
#define Texture_h__

#include "Resources.h"

BEGIN(Engine)

class CGameObject;

class ENGINE_DLL CTexture
	: public CResources
{
private:
	CTexture(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CTexture(void);

public:
	virtual CResources* CloneResource(CGameObject* pGameObj);

public:
	HRESULT LoadTexture(TEXTURETYPE eTextureType, const wstring& wstrFilePath, const WORD& wCnt);
	void Render(const DWORD& iIndex);

public:
	static CTexture* Create(LPDIRECT3DDEVICE9 pDevice
		, TEXTURETYPE eTextureType, const wstring& wstrFilePath, const WORD& wCnt);

private:
	void Release(void);

private:
	/*LPDIRECT3DTEXTURE9
	LPDIRECT3DCUBETEXTURE9*/
	typedef vector<IDirect3DBaseTexture9*>		VECTEXTURE;
	VECTEXTURE		m_vecTexture;

private:
	DWORD		m_dwContainerSize;
};

END

#endif // Texture_h__
/*!
 * \file VIBuffer.h
 * \date 2016/06/10 10:33
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

#ifndef VIBuffer_h__
#define VIBuffer_h__

#include "Resources.h"

BEGIN(Engine)

class CGameObject;

class ENGINE_DLL CVIBuffer
	: public CResources
{
protected:
	explicit CVIBuffer(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CVIBuffer(void);

public:
	void GetVtxInfo(void* pVertex);

public:
	void SetVtxInfo(void* pVertex);

public:
	virtual CResources* CloneResource(CGameObject* pGameObj) PURE;

public:
	virtual HRESULT CreateBuffer(void);

public:
	virtual void Render(void);

protected:
	void Release(void);

protected:
	LPDIRECT3DVERTEXBUFFER9		m_pVB;
	DWORD		m_dwVtxSize;
	DWORD		m_dwVtxCnt;
	DWORD		m_dwVtxFVF;

	LPDIRECT3DINDEXBUFFER9		m_pIB;
	DWORD		m_dwIdxSize;
	DWORD		m_dwTriCnt;
	D3DFORMAT	m_IdxFmt;
};

END

#endif // VIBuffer_h__
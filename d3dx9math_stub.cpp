//-----------------------------------------------------------------------------
// File : d3dx9math_stub.cpp
// Desc : Stub for d3dx9math
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "d3dx9math_stub.h"


namespace {
static constexpr HRESULT kD3D_OK               = 0;            // S_OK.
static constexpr HRESULT kD3DERR_INVALIDCALL   = MAKE_D3DHRESULT(2156);

} // namespace

///////////////////////////////////////////////////////////////////////////////
// Float16
///////////////////////////////////////////////////////////////////////////////

// Converts an array 32-bit floats to 16-bit floats
D3DXFLOAT16* STUB_API D3DXFloat32To16Array(D3DXFLOAT16 *pOut, const float *pIn, uint32_t n)
{
    assert(pOut != nullptr);
    assert(pIn  != nullptr);
    for(auto i=0u; i<n; ++i)
    {
        pOut[i] = D3DXFLOAT16(pIn[i]);
    }
    return pOut;
}

// Converts an array 16-bit floats to 32-bit floats
float* STUB_API D3DXFloat16To32Array(float *pOut, const D3DXFLOAT16 *pIn, uint32_t n)
{
    assert(pOut != nullptr);
    assert(pIn  != nullptr);
    for(auto i=0u; i<n; ++i)
    {
        pOut[i] = (float)pIn[i];
    }
    return pOut;
}

///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR2
///////////////////////////////////////////////////////////////////////////////

D3DXVECTOR2* STUB_API D3DXVec2Normalize(D3DXVECTOR2 *pOut, const D3DXVECTOR2 *pV)
{
    auto v   = DirectX::XMLoadFloat2(pV);
    auto ret = DirectX::XMVector2Normalize(v);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR2* STUB_API D3DXVec2Hermite
(
     D3DXVECTOR2*       pOut,
    const D3DXVECTOR2*  pV1,
    const D3DXVECTOR2*  pT1,
    const D3DXVECTOR2*  pV2,
    const D3DXVECTOR2*  pT2,
    float               s
)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pT1  != nullptr);
    assert(pV2  != nullptr);
    assert(pT2  != nullptr);

    auto v1  = DirectX::XMLoadFloat2(pV1);
    auto t1  = DirectX::XMLoadFloat2(pT1);
    auto v2  = DirectX::XMLoadFloat2(pV2);
    auto t2  = DirectX::XMLoadFloat2(pT2);
    auto vs  = DirectX::XMVectorSet(s, s, 0.0f, 0.0f);
    auto ret = DirectX::XMVectorHermiteV(v1, t1, v2, t2, vs);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR2* STUB_API D3DXVec2CatmullRom
(
    D3DXVECTOR2*        pOut,
    const D3DXVECTOR2*  pV0,
    const D3DXVECTOR2*  pV1,
    const D3DXVECTOR2*  pV2,
    const D3DXVECTOR2*  pV3,
    float               s
)
{
    assert(pOut != nullptr);
    assert(pV0  != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v0  = DirectX::XMLoadFloat2(pV0);
    auto v1  = DirectX::XMLoadFloat2(pV1);
    auto v2  = DirectX::XMLoadFloat2(pV2);
    auto v3  = DirectX::XMLoadFloat2(pV3);
    auto vs  = DirectX::XMVectorSet(s, s, 0.0f, 0.0f);
    auto ret = DirectX::XMVectorCatmullRomV(v0, v1, v2, v3, vs);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR2* STUB_API D3DXVec2BaryCentric
(
    D3DXVECTOR2*        pOut,
    const D3DXVECTOR2*  pV1,
    const D3DXVECTOR2*  pV2,
    const D3DXVECTOR2*  pV3,
    float               f,
    float               g
)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v1  = DirectX::XMLoadFloat2(pV1);
    auto v2  = DirectX::XMLoadFloat2(pV2);
    auto v3  = DirectX::XMLoadFloat2(pV3);
    auto vf  = DirectX::XMVectorSet(f, f, 0.0f, 0.0f);
    auto vg  = DirectX::XMVectorSet(g, g, 0.0f, 0.0f);
    auto ret = DirectX::XMVectorBaryCentricV(v1, v2, v3, vf, vg);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// Transform (x, y, 0, 1) by matrix.
D3DXVECTOR4* STUB_API D3DXVec2Transform
(
    D3DXVECTOR4*        pOut,
    const D3DXVECTOR2*  pV,
    const D3DXMATRIX*   pM
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat2(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector2Transform(vec, mat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Transform (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* STUB_API D3DXVec2TransformCoord
(
    D3DXVECTOR2*        pOut,
    const D3DXVECTOR2*  pV,
    const D3DXMATRIX*   pM
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat2(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector2TransformCoord(vec, mat);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}

// Transform (x, y, 0, 0) by matrix.
D3DXVECTOR2* STUB_API D3DXVec2TransformNormal
(
    D3DXVECTOR2*        pOut,
    const D3DXVECTOR2*  pV,
    const D3DXMATRIX*   pM
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat2(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector2TransformNormal(vec, mat);
    DirectX::XMStoreFloat2(pOut, ret);
    return pOut;
}
     
// Transform Array (x, y, 0, 1) by matrix.
D3DXVECTOR4* STUB_API D3DXVec2TransformArray
(
    D3DXVECTOR4*        pOut,
    uint32_t            OutStride,
    const D3DXVECTOR2*  pV,
    uint32_t            VStride,
    const D3DXMATRIX*   pM,
    uint32_t            n
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector2TransformStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Transform Array (x, y, 0, 1) by matrix, project result back into w=1.
D3DXVECTOR2* STUB_API D3DXVec2TransformCoordArray
(
    D3DXVECTOR2*        pOut,
    uint32_t            OutStride,
    const D3DXVECTOR2*  pV,
    uint32_t            VStride,
    const D3DXMATRIX*   pM,
    uint32_t            n
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector2TransformCoordStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Transform Array (x, y, 0, 0) by matrix.
D3DXVECTOR2* STUB_API D3DXVec2TransformNormalArray
(
    D3DXVECTOR2*        pOut,
    uint32_t            OutStride,
    const D3DXVECTOR2*  pV,
    uint32_t            VStride,
    const D3DXMATRIX*   pM,
    uint32_t            n
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector2TransformNormalStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR3
///////////////////////////////////////////////////////////////////////////////

D3DXVECTOR3* STUB_API D3DXVec3Normalize(D3DXVECTOR3 *pOut, const D3DXVECTOR3 *pV)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);

    auto vec = DirectX::XMLoadFloat3(pV);
    auto ret = DirectX::XMVector3Normalize(vec);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR3* STUB_API D3DXVec3Hermite
(
    D3DXVECTOR3*        pOut,
    const D3DXVECTOR3*  pV1,
    const D3DXVECTOR3*  pT1,
    const D3DXVECTOR3*  pV2,
    const D3DXVECTOR3*  pT2,
    float               s
)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pT1  != nullptr);
    assert(pV2  != nullptr);

    auto v1  = DirectX::XMLoadFloat3(pV1);
    auto t1  = DirectX::XMLoadFloat3(pT1);
    auto v2  = DirectX::XMLoadFloat3(pV2);
    auto t2  = DirectX::XMLoadFloat3(pT2);
    auto vs  = DirectX::XMVectorSet(s, s, s, 0.0f);
    auto ret = DirectX::XMVectorHermiteV(v1, t1, v2, t2, vs);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR3* STUB_API D3DXVec3CatmullRom
(
    D3DXVECTOR3*        pOut,
    const D3DXVECTOR3*  pV0,
    const D3DXVECTOR3*  pV1,
    const D3DXVECTOR3*  pV2,
    const D3DXVECTOR3*  pV3,
    float               s
)
{
    assert(pOut != nullptr);
    assert(pV0  != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v0  = DirectX::XMLoadFloat3(pV0);
    auto v1  = DirectX::XMLoadFloat3(pV1);
    auto v2  = DirectX::XMLoadFloat3(pV2);
    auto v3  = DirectX::XMLoadFloat3(pV3);
    auto vs  = DirectX::XMVectorSet(s, s, s, 0.0f);
    auto ret = DirectX::XMVectorCatmullRomV(v0, v1, v2, v3, vs);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR3* STUB_API D3DXVec3BaryCentric
(
    D3DXVECTOR3*        pOut,
    const D3DXVECTOR3*  pV1,
    const D3DXVECTOR3*  pV2,
    const D3DXVECTOR3*  pV3,
    float               f,
    float               g
)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v1  = DirectX::XMLoadFloat3(pV1);
    auto v2  = DirectX::XMLoadFloat3(pV2);
    auto v3  = DirectX::XMLoadFloat3(pV3);
    auto vf  = DirectX::XMVectorSet(f, f, f, 0.0f);
    auto vg  = DirectX::XMVectorSet(g, g, g, 0.0f);
    auto ret = DirectX::XMVectorBaryCentricV(v1, v2, v3, vf, vg);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Transform (x, y, z, 1) by matrix.
D3DXVECTOR4* STUB_API D3DXVec3Transform
(
    D3DXVECTOR4*        pOut,
    const D3DXVECTOR3*  pV,
    const D3DXMATRIX*   pM
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat3(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector3Transform(vec, mat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Transform (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* STUB_API D3DXVec3TransformCoord
(
    D3DXVECTOR3*        pOut,
    const D3DXVECTOR3*  pV,
    const D3DXMATRIX*   pM
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat3(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector3TransformCoord(vec, mat);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* STUB_API D3DXVec3TransformNormal
(
    D3DXVECTOR3*        pOut,
    const D3DXVECTOR3*  pV,
    const D3DXMATRIX*   pM
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat3(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector3TransformNormal(vec, mat);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Transform Array (x, y, z, 1) by matrix. 
D3DXVECTOR4* STUB_API D3DXVec3TransformArray
(
    D3DXVECTOR4*        pOut,
    uint32_t            OutStride,
    const D3DXVECTOR3*  pV,
    uint32_t            VStride,
    const D3DXMATRIX*   pM,
    uint32_t            n
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector3TransformStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Transform Array (x, y, z, 1) by matrix, project result back into w=1.
D3DXVECTOR3* STUB_API D3DXVec3TransformCoordArray
(
    D3DXVECTOR3*        pOut,
    uint32_t            OutStride,
    const D3DXVECTOR3*  pV,
    uint32_t            VStride,
    const D3DXMATRIX*   pM,
    uint32_t            n
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector3TransformCoordStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a 
// non-affine matrix, the matrix you pass to this function should be the 
// transpose of the inverse of the matrix you would use to transform a coord.
D3DXVECTOR3* STUB_API D3DXVec3TransformNormalArray
(
    D3DXVECTOR3*        pOut,
    uint32_t            OutStride,
    const D3DXVECTOR3*  pV,
    uint32_t            VStride,
    const D3DXMATRIX*   pM,
    uint32_t            n
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector3TransformNormalStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}

// Project vector from object space into screen space
D3DXVECTOR3* STUB_API D3DXVec3Project
(
    D3DXVECTOR3*        pOut,
    const D3DXVECTOR3*  pV,
    const D3DVIEWPORT9* pViewport,
    const D3DXMATRIX*   pProjection,
    const D3DXMATRIX*   pView,
    const D3DXMATRIX*   pWorld
)
{
    assert(pOut        != nullptr);
    assert(pV          != nullptr);
    assert(pViewport   != nullptr);
    assert(pProjection != nullptr);
    assert(pView       != nullptr);
    assert(pWorld      != nullptr);

    auto x = float(pViewport->X);
    auto y = float(pViewport->Y);
    auto w = float(pViewport->Width);
    auto h = float(pViewport->Height);

    auto vec   = DirectX::XMLoadFloat3(pV);
    auto proj  = DirectX::XMLoadFloat4x4(pProjection);
    auto view  = DirectX::XMLoadFloat4x4(pView);
    auto world = DirectX::XMLoadFloat4x4(pWorld);
    auto ret   = DirectX::XMVector3Project(vec, x, y, w, h, pViewport->MinZ, pViewport->MaxZ, proj, view, world);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Project vector from screen space into object space
D3DXVECTOR3* STUB_API D3DXVec3Unproject
(
    D3DXVECTOR3*        pOut,
    const D3DXVECTOR3*  pV,
    const D3DVIEWPORT9* pViewport,
    const D3DXMATRIX*   pProjection,
    const D3DXMATRIX*   pView,
    const D3DXMATRIX*   pWorld
)
{
    assert(pOut        != nullptr);
    assert(pV          != nullptr);
    assert(pViewport   != nullptr);
    assert(pProjection != nullptr);
    assert(pView       != nullptr);
    assert(pWorld      != nullptr);

    auto x = float(pViewport->X);
    auto y = float(pViewport->Y);
    auto w = float(pViewport->Width);
    auto h = float(pViewport->Height);

    auto vec   = DirectX::XMLoadFloat3(pV);
    auto proj  = DirectX::XMLoadFloat4x4(pProjection);
    auto view  = DirectX::XMLoadFloat4x4(pView);
    auto world = DirectX::XMLoadFloat4x4(pWorld);
    auto ret   = DirectX::XMVector3Unproject(vec, x, y, w, h, pViewport->MinZ, pViewport->MaxZ, proj, view, world);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}
      
// Project vector Array from object space into screen space
D3DXVECTOR3* STUB_API D3DXVec3ProjectArray
(
    D3DXVECTOR3*        pOut,
    uint32_t            OutStride,
    const D3DXVECTOR3*  pV,
    uint32_t            VStride,
    const D3DVIEWPORT9* pViewport,
    const D3DXMATRIX*   pProjection,
    const D3DXMATRIX*   pView,
    const D3DXMATRIX*   pWorld,
    uint32_t            n
)
{
    assert(pOut        != nullptr);
    assert(pV          != nullptr);
    assert(pViewport   != nullptr);
    assert(pProjection != nullptr);
    assert(pView       != nullptr);
    assert(pWorld      != nullptr);

    auto x = float(pViewport->X);
    auto y = float(pViewport->Y);
    auto w = float(pViewport->Width);
    auto h = float(pViewport->Height);

    auto proj  = DirectX::XMLoadFloat4x4(pProjection);
    auto view  = DirectX::XMLoadFloat4x4(pView);
    auto world = DirectX::XMLoadFloat4x4(pWorld);

    DirectX::XMVector3ProjectStream(
        pOut, OutStride, pV, VStride, n, x, y, w, h, pViewport->MinZ, pViewport->MaxZ, proj, view, world);
    return pOut;
}

// Project vector Array from screen space into object space
D3DXVECTOR3* STUB_API D3DXVec3UnprojectArray
(
    D3DXVECTOR3*        pOut,
    uint32_t            OutStride,
    const D3DXVECTOR3*  pV,
    uint32_t            VStride,
    const D3DVIEWPORT9* pViewport,
    const D3DXMATRIX*   pProjection,
    const D3DXMATRIX*   pView,
    const D3DXMATRIX*   pWorld,
    uint32_t            n
)
{
    assert(pOut        != nullptr);
    assert(pV          != nullptr);
    assert(pViewport   != nullptr);
    assert(pProjection != nullptr);
    assert(pView       != nullptr);
    assert(pWorld      != nullptr);

    auto x = float(pViewport->X);
    auto y = float(pViewport->Y);
    auto w = float(pViewport->Width);
    auto h = float(pViewport->Height);

    auto proj  = DirectX::XMLoadFloat4x4(pProjection);
    auto view  = DirectX::XMLoadFloat4x4(pView);
    auto world = DirectX::XMLoadFloat4x4(pWorld);

    DirectX::XMVector3UnprojectStream(
        pOut, OutStride, pV, VStride, n, x, y, w, h, pViewport->MinZ, pViewport->MaxZ, proj, view, world);
    return pOut;
}


///////////////////////////////////////////////////////////////////////////////
// D3DXVECTOR4
///////////////////////////////////////////////////////////////////////////////

// Cross-product in 4 dimensions.
D3DXVECTOR4* STUB_API D3DXVec4Cross
(
    D3DXVECTOR4*        pOut,
    const D3DXVECTOR4*  pV1,
    const D3DXVECTOR4*  pV2,
    const D3DXVECTOR4*  pV3
)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v1  = DirectX::XMLoadFloat4(pV1);
    auto v2  = DirectX::XMLoadFloat4(pV2);
    auto v3  = DirectX::XMLoadFloat4(pV3);
    auto ret = DirectX::XMVector4Cross(v1, v2, v3);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

D3DXVECTOR4* STUB_API D3DXVec4Normalize
(
    D3DXVECTOR4*        pOut,
    const D3DXVECTOR4*  pV
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);

    auto vec = DirectX::XMLoadFloat4(pV);
    auto ret = DirectX::XMVector4Normalize(vec);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Hermite interpolation between position V1, tangent T1 (when s == 0)
// and position V2, tangent T2 (when s == 1).
D3DXVECTOR4* STUB_API D3DXVec4Hermite
(
    D3DXVECTOR4*        pOut,
    const D3DXVECTOR4*  pV1,
    const D3DXVECTOR4*  pT1,
    const D3DXVECTOR4*  pV2,
    const D3DXVECTOR4*  pT2,
    float               s 
)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pT1  != nullptr);
    assert(pV2  != nullptr);
    assert(pT2  != nullptr);

    auto v1  = DirectX::XMLoadFloat4(pV1);
    auto t1  = DirectX::XMLoadFloat4(pT1);
    auto v2  = DirectX::XMLoadFloat4(pV2);
    auto t2  = DirectX::XMLoadFloat4(pT2);
    auto vs  = DirectX::XMVectorSet(s, s, s, s);
    auto ret = DirectX::XMVectorHermiteV(v1, t1, v2, t2, vs);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)
D3DXVECTOR4* STUB_API D3DXVec4CatmullRom
(
    D3DXVECTOR4*        pOut,
    const D3DXVECTOR4*  pV0,
    const D3DXVECTOR4*  pV1,
    const D3DXVECTOR4*  pV2,
    const D3DXVECTOR4*  pV3,
    float               s
)
{
    assert(pOut != nullptr);
    assert(pV0  != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v0  = DirectX::XMLoadFloat4(pV0);
    auto v1  = DirectX::XMLoadFloat4(pV1);
    auto v2  = DirectX::XMLoadFloat4(pV2);
    auto v3  = DirectX::XMLoadFloat4(pV3);
    auto vs  = DirectX::XMVectorSet(s, s, s, s);
    auto ret = DirectX::XMVectorCatmullRomV(v0, v1, v2, v3, vs);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)
D3DXVECTOR4* STUB_API D3DXVec4BaryCentric
(
    D3DXVECTOR4*        pOut,
    const D3DXVECTOR4*  pV1,
    const D3DXVECTOR4*  pV2,
    const D3DXVECTOR4*  pV3,
    float               f,
    float               g
)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v1  = DirectX::XMLoadFloat4(pV1);
    auto v2  = DirectX::XMLoadFloat4(pV2);
    auto v3  = DirectX::XMLoadFloat4(pV3);
    auto vf  = DirectX::XMVectorSet(f, f, f, f);
    auto vg  = DirectX::XMVectorSet(g, g, g, g);
    auto ret = DirectX::XMVectorBaryCentricV(v1, v2, v3, vf, vg);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Transform vector by matrix.
D3DXVECTOR4* STUB_API D3DXVec4Transform
(
    D3DXVECTOR4*        pOut,
    const D3DXVECTOR4*  pV,
    const D3DXMATRIX*   pM
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto vec = DirectX::XMLoadFloat4(pV);
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMVector4Transform(vec, mat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}
    
// Transform vector array by matrix.
D3DXVECTOR4* STUB_API D3DXVec4TransformArray
(
    D3DXVECTOR4*        pOut,
    uint32_t            OutStride,
    const D3DXVECTOR4*  pV,
    uint32_t            VStride,
    const D3DXMATRIX*   pM,
    uint32_t            n
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    DirectX::XMVector4TransformStream(pOut, OutStride, pV, VStride, n, mat);
    return pOut;
}


///////////////////////////////////////////////////////////////////////////////
// D3DXMATRIX
///////////////////////////////////////////////////////////////////////////////

float STUB_API D3DXMatrixDeterminant(const D3DXMATRIX *pM)
{
    assert(pM != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMMatrixDeterminant(mat);
    return DirectX::XMVectorGetX(ret);
}

HRESULT STUB_API D3DXMatrixDecompose
(
    D3DXVECTOR3*        pOutScale,
    D3DXQUATERNION*     pOutRotation,
    D3DXVECTOR3*        pOutTranslation,
    const D3DXMATRIX*   pM
)
{
    assert(pOutScale       != nullptr);
    assert(pOutRotation    != nullptr);
    assert(pOutTranslation != nullptr);
    assert(pM              != nullptr);

    DirectX::XMVECTOR scale;
    DirectX::XMVECTOR rotate;
    DirectX::XMVECTOR translation;
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMMatrixDecompose(&scale, &rotate, &translation, mat);
    if (!ret)
    {
        return kD3DERR_INVALIDCALL;// D3DERR_INVALIDCALL
    }

    DirectX::XMStoreFloat3(pOutScale, scale);
    DirectX::XMStoreFloat4(pOutRotation, rotate);
    DirectX::XMStoreFloat3(pOutTranslation, translation);

    return kD3D_OK; // S_OK.
}

D3DXMATRIX* STUB_API D3DXMatrixTranspose(D3DXMATRIX *pOut, const D3DXMATRIX *pM)
{
    assert(pOut != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMMatrixTranspose(mat);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Matrix multiplication.  The result represents the transformation M2
// followed by the transformation M1.  (Out = M1 * M2)
D3DXMATRIX* STUB_API D3DXMatrixMultiply
(
    D3DXMATRIX*         pOut,
    const D3DXMATRIX*   pM1,
    const D3DXMATRIX*   pM2
)
{
    assert(pOut != nullptr);
    assert(pM1  != nullptr);
    assert(pM2  != nullptr);

    auto m1  = DirectX::XMLoadFloat4x4(pM1);
    auto m2  = DirectX::XMLoadFloat4x4(pM2);
    auto ret = DirectX::XMMatrixMultiply(m1, m2);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Matrix multiplication, followed by a transpose. (Out = T(M1 * M2))
D3DXMATRIX* STUB_API D3DXMatrixMultiplyTranspose
(
    D3DXMATRIX*         pOut,
    const D3DXMATRIX*   pM1,
    const D3DXMATRIX*   pM2
)
{
    assert(pOut != nullptr);
    assert(pM1  != nullptr);
    assert(pM2  != nullptr);

    auto m1  = DirectX::XMLoadFloat4x4(pM1);
    auto m2  = DirectX::XMLoadFloat4x4(pM2);
    auto ret = DirectX::XMMatrixMultiplyTranspose(m1, m2);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Calculate inverse of matrix.  Inversion my fail, in which case NULL will
// be returned.  The determinant of pM is also returned it pfDeterminant
// is non-NULL.
D3DXMATRIX* STUB_API D3DXMatrixInverse
(
    D3DXMATRIX*         pOut,
    float*              pDeterminant,
    const D3DXMATRIX*   pM
)
{
    assert(pOut != nullptr);
    assert(pM != nullptr);

    DirectX::XMVECTOR det;
    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMMatrixInverse(&det, mat);
    if (pDeterminant != nullptr)
    {
        DirectX::XMStoreFloat(pDeterminant, det);
    }
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which scales by (sx, sy, sz)
D3DXMATRIX* STUB_API D3DXMatrixScaling(D3DXMATRIX *pOut, float sx, float sy, float sz)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixScaling(sx, sy, sz);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which translates by (x, y, z)
D3DXMATRIX* STUB_API D3DXMatrixTranslation(D3DXMATRIX *pOut, float x, float y, float z)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixTranslation(x, y, z);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which rotates around the X axis
D3DXMATRIX* STUB_API D3DXMatrixRotationX(D3DXMATRIX *pOut, float Angle)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixRotationX(Angle);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which rotates around the Y axis
D3DXMATRIX* STUB_API D3DXMatrixRotationY(D3DXMATRIX *pOut, float Angle)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixRotationY(Angle);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which rotates around the Z axis
D3DXMATRIX* STUB_API D3DXMatrixRotationZ(D3DXMATRIX *pOut, float Angle)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixRotationZ(Angle);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which rotates around an arbitrary axis
D3DXMATRIX* STUB_API D3DXMatrixRotationAxis(D3DXMATRIX *pOut, const D3DXVECTOR3 *pV, float Angle)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);

    auto axis = DirectX::XMLoadFloat3(pV);
    auto ret  = DirectX::XMMatrixRotationAxis(axis, Angle);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix from a quaternion
D3DXMATRIX* STUB_API D3DXMatrixRotationQuaternion(D3DXMATRIX *pOut, const D3DXQUATERNION *pQ)
{
    assert(pOut != nullptr);
    assert(pQ   != nullptr);

    auto quat = DirectX::XMLoadFloat4(pQ);
    auto ret  = DirectX::XMMatrixRotationQuaternion(quat);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXMATRIX* STUB_API D3DXMatrixRotationYawPitchRoll(D3DXMATRIX *pOut, float Yaw, float Pitch, float Roll)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixRotationRollPitchYaw(Pitch, Yaw, Roll);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build transformation matrix.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* STUB_API D3DXMatrixTransformation
(
    D3DXMATRIX*             pOut,
    const D3DXVECTOR3*      pScalingCenter,
    const D3DXQUATERNION*   pScalingRotation,
    const D3DXVECTOR3*      pScaling,
    const D3DXVECTOR3*      pRotationCenter,
    const D3DXQUATERNION*   pRotation,
    const D3DXVECTOR3*      pTranslation
)
{
    assert(pOut             != nullptr);
    assert(pScalingCenter   != nullptr);
    assert(pScalingRotation != nullptr);
    assert(pScaling         != nullptr);
    assert(pRotationCenter  != nullptr);
    assert(pRotation        != nullptr);
    assert(pTranslation     != nullptr);

    auto scalingCenter      = DirectX::XMLoadFloat3(pScalingCenter);
    auto scalingRotation    = DirectX::XMLoadFloat4(pScalingRotation);
    auto scaling            = DirectX::XMLoadFloat3(pScaling);
    auto rotationCenter     = DirectX::XMLoadFloat3(pRotationCenter);
    auto rotation           = DirectX::XMLoadFloat4(pRotation);
    auto translation        = DirectX::XMLoadFloat3(pTranslation);

    auto ret = DirectX::XMMatrixTransformation(scalingCenter, scalingRotation, scaling, rotationCenter, rotation, translation);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build 2D transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* STUB_API D3DXMatrixTransformation2D
(
    D3DXMATRIX*         pOut,
    const D3DXVECTOR2*  pScalingCenter, 
    float               ScalingRotation,
    const D3DXVECTOR2*  pScaling, 
    const D3DXVECTOR2*  pRotationCenter,
    float               Rotation, 
    const D3DXVECTOR2*  pTranslation
)
{
    assert(pOut            != nullptr);
    assert(pScalingCenter  != nullptr);
    assert(pScaling        != nullptr);
    assert(pRotationCenter != nullptr);
    assert(pTranslation    != nullptr);

    auto scalingCenter  = DirectX::XMLoadFloat2(pScalingCenter);
    auto scaling        = DirectX::XMLoadFloat2(pScaling);
    auto rotationCenter = DirectX::XMLoadFloat2(pRotationCenter);
    auto translation    = DirectX::XMLoadFloat2(pTranslation);

    auto ret = DirectX::XMMatrixTransformation2D(scalingCenter, ScalingRotation, scaling, rotationCenter, Rotation, translation);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build affine transformation matrix.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* STUB_API D3DXMatrixAffineTransformation
(
    D3DXMATRIX*             pOut,
    float                   Scaling,
    const D3DXVECTOR3*      pRotationCenter,
    const D3DXQUATERNION*   pRotation,
    const D3DXVECTOR3*      pTranslation
)
{
    assert(pOut            != nullptr);
    assert(pRotationCenter != nullptr);
    assert(pRotation       != nullptr);
    assert(pTranslation    != nullptr);

    auto scaling        = DirectX::XMVectorSet(Scaling, Scaling, Scaling, 1.0f);
    auto rotationCenter = DirectX::XMLoadFloat3(pRotationCenter);
    auto rotation       = DirectX::XMLoadFloat4(pRotation);
    auto translation    = DirectX::XMLoadFloat3(pTranslation);

    auto ret = DirectX::XMMatrixAffineTransformation(scaling, rotationCenter, rotation, translation);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build 2D affine transformation matrix in XY plane.  NULL arguments are treated as identity.
// Mout = Ms * Mrc-1 * Mr * Mrc * Mt
D3DXMATRIX* STUB_API D3DXMatrixAffineTransformation2D
(
    D3DXMATRIX*         pOut,
    float               Scaling,
    const D3DXVECTOR2*  pRotationCenter, 
    float               Rotation,
    const D3DXVECTOR2*  pTranslation
)
{
    assert(pOut            != nullptr);
    assert(pRotationCenter != nullptr);
    assert(pTranslation    != nullptr);

    auto scaling        = DirectX::XMVectorSet(Scaling, Scaling, 1.0f, 1.0f);
    auto rotationCenter = DirectX::XMLoadFloat2(pRotationCenter);
    auto translation    = DirectX::XMLoadFloat2(pTranslation);

    auto ret = DirectX::XMMatrixAffineTransformation2D(scaling, rotationCenter, Rotation, translation);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a lookat matrix. (right-handed)
D3DXMATRIX* STUB_API D3DXMatrixLookAtRH
(
    D3DXMATRIX*         pOut,
    const D3DXVECTOR3*  pEye,
    const D3DXVECTOR3*  pAt,
    const D3DXVECTOR3*  pUp
)
{
    assert(pOut != nullptr);
    assert(pEye != nullptr);
    assert(pAt  != nullptr);
    assert(pUp  != nullptr);

    auto eye = DirectX::XMLoadFloat3(pEye);
    auto at  = DirectX::XMLoadFloat3(pAt);
    auto up  = DirectX::XMLoadFloat3(pUp);
    auto ret = DirectX::XMMatrixLookAtRH(eye, at, up);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a lookat matrix. (left-handed)
D3DXMATRIX* STUB_API D3DXMatrixLookAtLH
(
    D3DXMATRIX*         pOut,
    const D3DXVECTOR3*  pEye,
    const D3DXVECTOR3*  pAt,
    const D3DXVECTOR3*  pUp
)
{
    assert(pOut != nullptr);
    assert(pEye != nullptr);
    assert(pAt  != nullptr);
    assert(pUp  != nullptr);

    auto eye = DirectX::XMLoadFloat3(pEye);
    auto at  = DirectX::XMLoadFloat3(pAt);
    auto up  = DirectX::XMLoadFloat3(pUp);
    auto ret = DirectX::XMMatrixLookAtLH(eye, at, up);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* STUB_API D3DXMatrixPerspectiveRH
(
    D3DXMATRIX* pOut,
    float       w,
    float       h,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixPerspectiveRH(w, h, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* STUB_API D3DXMatrixPerspectiveLH
(
    D3DXMATRIX* pOut,
    float       w,
    float       h,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixPerspectiveLH(w, h, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* STUB_API D3DXMatrixPerspectiveFovRH
(
    D3DXMATRIX* pOut,
    float       fovy,
    float       Aspect,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixPerspectiveFovRH(fovy, Aspect, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* STUB_API D3DXMatrixPerspectiveFovLH
(
    D3DXMATRIX* pOut,
    float       fovy,
    float       Aspect,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixPerspectiveFovLH(fovy, Aspect, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (right-handed)
D3DXMATRIX* STUB_API D3DXMatrixPerspectiveOffCenterRH
(
    D3DXMATRIX* pOut,
    float       l,
    float       r,
    float       b,
    float       t,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixPerspectiveOffCenterRH(l, r, b, t, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a perspective projection matrix. (left-handed)
D3DXMATRIX* STUB_API D3DXMatrixPerspectiveOffCenterLH
(
    D3DXMATRIX* pOut,
    float       l,
    float       r,
    float       b,
    float       t,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixPerspectiveOffCenterLH(l, r, b, t, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* STUB_API D3DXMatrixOrthoRH
(
    D3DXMATRIX* pOut,
    float       w,
    float       h,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixOrthographicRH(w, h, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* STUB_API D3DXMatrixOrthoLH
(
    D3DXMATRIX* pOut,
    float       w,
    float       h,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixOrthographicLH(w, h, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build an ortho projection matrix. (right-handed)
D3DXMATRIX* STUB_API D3DXMatrixOrthoOffCenterRH
(
    D3DXMATRIX* pOut,
    float       l,
    float       r,
    float       b,
    float       t,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixOrthographicOffCenterRH(l, r, b, t, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build an ortho projection matrix. (left-handed)
D3DXMATRIX* STUB_API D3DXMatrixOrthoOffCenterLH
(
    D3DXMATRIX* pOut,
    float       l,
    float       r,
    float       b,
    float       t,
    float       zn,
    float       zf
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMMatrixOrthographicOffCenterLH(l, r, b, t, zn, zf);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which flattens geometry into a plane, as if casting
// a shadow from a light.
D3DXMATRIX* STUB_API D3DXMatrixShadow
(
    D3DXMATRIX*         pOut,
    const D3DXVECTOR4*  pLight,
    const D3DXPLANE*    pPlane
)
{
    assert(pOut  != nullptr);
    assert(pLight != nullptr);
    assert(pPlane != nullptr);

    auto plane = DirectX::XMVectorSet(pPlane->a, pPlane->b, pPlane->c, pPlane->d);
    auto light = DirectX::XMLoadFloat4(pLight);

    auto ret = DirectX::XMMatrixShadow(plane, light);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

// Build a matrix which reflects the coordinate system about a plane
D3DXMATRIX* STUB_API D3DXMatrixReflect(D3DXMATRIX *pOut, const D3DXPLANE *pPlane)
{
    assert(pOut   != nullptr);
    assert(pPlane != nullptr);

    auto plane = DirectX::XMVectorSet(pPlane->a, pPlane->b, pPlane->c, pPlane->d);

    auto ret = DirectX::XMMatrixReflect(plane);
    DirectX::XMStoreFloat4x4(pOut, ret);
    return pOut;
}

///////////////////////////////////////////////////////////////////////////////
// D3DXQUATERNION
///////////////////////////////////////////////////////////////////////////////

// Compute a quaternin's axis and angle of rotation. Expects unit quaternions.
void STUB_API D3DXQuaternionToAxisAngle
(
    const D3DXQUATERNION*   pQ,
    D3DXVECTOR3*            pAxis,
    float*                  pAngle
)
{
    assert(pQ     != nullptr);
    assert(pAxis  != nullptr);
    assert(pAngle != nullptr);

    auto quat = DirectX::XMLoadFloat4(pQ);

    DirectX::XMVECTOR axis;
    DirectX::XMQuaternionToAxisAngle(&axis, pAngle, quat);

    DirectX::XMStoreFloat3(pAxis, axis);
}

// Build a quaternion from a rotation matrix.
D3DXQUATERNION* STUB_API D3DXQuaternionRotationMatrix(D3DXQUATERNION *pOut, const D3DXMATRIX *pM)
{
    assert(pOut != nullptr);
    assert(pM   != nullptr);

    auto mat = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMQuaternionRotationMatrix(mat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Rotation about arbitrary axis.
D3DXQUATERNION* STUB_API D3DXQuaternionRotationAxis
(
    D3DXQUATERNION*     pOut,
    const D3DXVECTOR3*  pV,
    float               Angle
)
{
    assert(pOut != nullptr);
    assert(pV   != nullptr);

    auto v   = DirectX::XMLoadFloat3(pV);
    auto ret = DirectX::XMQuaternionRotationAxis(v, Angle);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Yaw around the Y axis, a pitch around the X axis,
// and a roll around the Z axis.
D3DXQUATERNION* STUB_API D3DXQuaternionRotationYawPitchRoll
(
    D3DXQUATERNION* pOut,
    float           Yaw,
    float           Pitch,
    float           Roll
)
{
    assert(pOut != nullptr);

    auto ret = DirectX::XMQuaternionRotationRollPitchYaw(Pitch, Yaw, Roll);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Quaternion multiplication.  The result represents the rotation Q2
// followed by the rotation Q1.  (Out = Q2 * Q1)
D3DXQUATERNION* STUB_API D3DXQuaternionMultiply
(
    D3DXQUATERNION*         pOut,
    const D3DXQUATERNION*   pQ1,
    const D3DXQUATERNION*   pQ2
)
{
    assert(pOut != nullptr);
    assert(pQ1  != nullptr);
    assert(pQ2  != nullptr);

    auto q1 = DirectX::XMLoadFloat4(pQ1);
    auto q2 = DirectX::XMLoadFloat4(pQ2);
    auto ret = DirectX::XMQuaternionMultiply(q1, q2);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

D3DXQUATERNION* STUB_API D3DXQuaternionNormalize(D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ)
{
    assert(pOut != nullptr);
    assert(pQ   != nullptr);

    auto quat = DirectX::XMLoadFloat4(pQ);
    auto ret  = DirectX::XMQuaternionNormalize(quat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Conjugate and re-norm
D3DXQUATERNION* STUB_API D3DXQuaternionInverse(D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ)
{
    assert(pOut != nullptr);
    assert(pQ   != nullptr);

    auto quat = DirectX::XMLoadFloat4(pQ);
    auto ret  = DirectX::XMQuaternionInverse(quat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Expects unit quaternions.
// if q = (cos(theta), sin(theta) * v); ln(q) = (0, theta * v)
D3DXQUATERNION* STUB_API D3DXQuaternionLn(D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ)
{
    assert(pOut != nullptr);
    assert(pQ   != nullptr);

    auto quat = DirectX::XMLoadFloat4(pQ);
    auto ret  = DirectX::XMQuaternionLn(quat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Expects pure quaternions. (w == 0)  w is ignored in calculation.
// if q = (0, theta * v); exp(q) = (cos(theta), sin(theta) * v)
D3DXQUATERNION* STUB_API D3DXQuaternionExp(D3DXQUATERNION *pOut, const D3DXQUATERNION *pQ)
{
    assert(pOut != nullptr);
    assert(pQ   != nullptr);

    auto quat = DirectX::XMLoadFloat4(pQ);
    auto ret  = DirectX::XMQuaternionExp(quat);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}
      
// Spherical linear interpolation between Q1 (t == 0) and Q2 (t == 1).
// Expects unit quaternions.
D3DXQUATERNION* STUB_API D3DXQuaternionSlerp
(
    D3DXQUATERNION*         pOut,
    const D3DXQUATERNION*   pQ1,
    const D3DXQUATERNION*   pQ2,
    float                   t
)
{
    assert(pOut != nullptr);
    assert(pQ1  != nullptr);
    assert(pQ2  != nullptr);

    auto q1  = DirectX::XMLoadFloat4(pQ1);
    auto q2  = DirectX::XMLoadFloat4(pQ2);
    auto ret = DirectX::XMQuaternionSlerp(q1, q2, t);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Spherical quadrangle interpolation.
// Slerp(Slerp(Q1, C, t), Slerp(A, B, t), 2t(1-t))
D3DXQUATERNION* STUB_API D3DXQuaternionSquad
(
    D3DXQUATERNION*         pOut,
    const D3DXQUATERNION*   pQ1,
    const D3DXQUATERNION*   pA,
    const D3DXQUATERNION*   pB,
    const D3DXQUATERNION*   pC,
    float                   t
)
{
    assert(pOut != nullptr);
    assert(pQ1  != nullptr);
    assert(pA   != nullptr);
    assert(pB   != nullptr);
    assert(pC   != nullptr);

    auto q1  = DirectX::XMLoadFloat4(pQ1);
    auto a   = DirectX::XMLoadFloat4(pA);
    auto b   = DirectX::XMLoadFloat4(pB);
    auto c   = DirectX::XMLoadFloat4(pC);
    auto ret = DirectX::XMQuaternionSquad(q1, a, b, c, t);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}

// Setup control points for spherical quadrangle interpolation
// from Q1 to Q2.  The control points are chosen in such a way 
// to ensure the continuity of tangents with adjacent segments.
void STUB_API D3DXQuaternionSquadSetup
(
    D3DXQUATERNION*         pAOut,
    D3DXQUATERNION*         pBOut,
    D3DXQUATERNION*         pCOut,
    const D3DXQUATERNION*   pQ0,
    const D3DXQUATERNION*   pQ1, 
    const D3DXQUATERNION*   pQ2,
    const D3DXQUATERNION*   pQ3
)
{
    assert(pAOut != nullptr);
    assert(pBOut != nullptr);
    assert(pCOut != nullptr);
    assert(pQ0   != nullptr);
    assert(pQ1   != nullptr);
    assert(pQ2   != nullptr);
    assert(pQ3   != nullptr);

    auto q0 = DirectX::XMLoadFloat4(pQ0);
    auto q1 = DirectX::XMLoadFloat4(pQ1);
    auto q2 = DirectX::XMLoadFloat4(pQ2);
    auto q3 = DirectX::XMLoadFloat4(pQ3);

    DirectX::XMVECTOR a, b, c;
    DirectX::XMQuaternionSquadSetup(&a, &b, &c, q0, q1, q2, q3);
    DirectX::XMStoreFloat4(pAOut, a);
    DirectX::XMStoreFloat4(pBOut, b);
    DirectX::XMStoreFloat4(pCOut, c);
}

// Barycentric interpolation.
// Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))
D3DXQUATERNION* STUB_API D3DXQuaternionBaryCentric
(
    D3DXQUATERNION*         pOut,
    const D3DXQUATERNION*   pQ1,
    const D3DXQUATERNION*   pQ2,
    const D3DXQUATERNION*   pQ3,
    float                   f,
    float                   g
)
{
    assert(pOut != nullptr);
    assert(pQ1  != nullptr);
    assert(pQ2  != nullptr);
    assert(pQ3  != nullptr);

    auto q1  = DirectX::XMLoadFloat4(pQ1);
    auto q2  = DirectX::XMLoadFloat4(pQ2);
    auto q3  = DirectX::XMLoadFloat4(pQ3);
    auto ret = DirectX::XMQuaternionBaryCentric(q1, q2, q3, f, g);
    DirectX::XMStoreFloat4(pOut, ret);
    return pOut;
}


///////////////////////////////////////////////////////////////////////////////
// D3DXPLANE
///////////////////////////////////////////////////////////////////////////////

// Normalize plane (so that |a,b,c| == 1)
D3DXPLANE* STUB_API D3DXPlaneNormalize(D3DXPLANE *pOut, const D3DXPLANE *pP)
{
    assert(pOut != nullptr);
    assert(pP   != nullptr);

    auto p   = DirectX::XMLoadFloat4((DirectX::XMFLOAT4*)pP);
    auto ret = DirectX::XMPlaneNormalize(p);
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)pOut, ret);
    return pOut;
}

// Find the intersection between a plane and a line.  If the line is
// parallel to the plane, NULL is returned.
D3DXVECTOR3* STUB_API D3DXPlaneIntersectLine
(
    D3DXVECTOR3*        pOut,
    const D3DXPLANE*    pP,
    const D3DXVECTOR3*  pV1,
    const D3DXVECTOR3*  pV2
)
{
    assert(pOut != nullptr);
    assert(pP   != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);

    auto p   = DirectX::XMLoadFloat4((DirectX::XMFLOAT4*)pP);
    auto v1  = DirectX::XMLoadFloat3(pV1);
    auto v2  = DirectX::XMLoadFloat3(pV2);
    auto ret = DirectX::XMPlaneIntersectLine(p, v1, v2);
    DirectX::XMStoreFloat3(pOut, ret);
    return pOut;
}

// Construct a plane from a point and a normal
D3DXPLANE* STUB_API D3DXPlaneFromPointNormal
(
    D3DXPLANE*          pOut,
    const D3DXVECTOR3*  pPoint,
    const D3DXVECTOR3*  pNormal
)
{
    assert(pOut    != nullptr);
    assert(pPoint  != nullptr);
    assert(pNormal != nullptr);

    auto p   = DirectX::XMLoadFloat3(pPoint);
    auto n   = DirectX::XMLoadFloat3(pNormal);
    auto ret = DirectX::XMPlaneFromPointNormal(p, n);
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)pOut, ret);
    return pOut;
}

// Construct a plane from 3 points
D3DXPLANE* STUB_API D3DXPlaneFromPoints
(
    D3DXPLANE*          pOut,
    const D3DXVECTOR3*  pV1,
    const D3DXVECTOR3*  pV2,
    const D3DXVECTOR3*  pV3
)
{
    assert(pOut != nullptr);
    assert(pV1  != nullptr);
    assert(pV2  != nullptr);
    assert(pV3  != nullptr);

    auto v1  = DirectX::XMLoadFloat3(pV1);
    auto v2  = DirectX::XMLoadFloat3(pV2);
    auto v3  = DirectX::XMLoadFloat3(pV3);
    auto ret = DirectX::XMPlaneFromPoints(v1, v2, v3);
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)pOut, ret);
    return pOut;
}

// Transform a plane by a matrix.  The vector (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* STUB_API D3DXPlaneTransform
(
    D3DXPLANE*          pOut,
    const D3DXPLANE*    pP,
    const D3DXMATRIX*   pM
)
{
    assert(pOut != nullptr);
    assert(pP   != nullptr);
    assert(pM   != nullptr);

    auto p   = DirectX::XMLoadFloat4((DirectX::XMFLOAT4*)pP);
    auto m   = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMPlaneTransform(p, m);
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)pOut, ret);
    return pOut;
}
    
// Transform an array of planes by a matrix.  The vectors (a,b,c) must be normal.
// M should be the inverse transpose of the transformation desired.
D3DXPLANE* STUB_API D3DXPlaneTransformArray
(
    D3DXPLANE*          pOut,
    uint32_t            OutStride,
    const D3DXPLANE*    pP,
    uint32_t            PStride,
    const D3DXMATRIX*   pM,
    uint32_t            n
)
{
    assert(pOut != nullptr);
    assert(pP   != nullptr);
    assert(pM   != nullptr);
    
    auto m   = DirectX::XMLoadFloat4x4(pM);
    auto ret = DirectX::XMPlaneTransformStream(
        (DirectX::XMFLOAT4*)pOut, OutStride, (DirectX::XMFLOAT4*)pP, PStride, n, m);
    return pOut;
}


///////////////////////////////////////////////////////////////////////////////
// D3DXCOLOR
///////////////////////////////////////////////////////////////////////////////

// Interpolate r,g,b between desaturated color and color.
// DesaturatedColor + s(Color - DesaturatedColor)
D3DXCOLOR* STUB_API D3DXColorAdjustSaturation(D3DXCOLOR *pOut, const D3DXCOLOR *pC, float s)
{
    assert(pOut != nullptr);

    auto c   = DirectX::XMLoadFloat4((DirectX::XMFLOAT4*)pC);
    auto ret = DirectX::XMColorAdjustSaturation(c, s);
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)pOut, ret);
    return pOut;
}

// Interpolate r,g,b between 50% grey and color.  Grey + s(Color - Grey)
D3DXCOLOR* STUB_API D3DXColorAdjustContrast(D3DXCOLOR *pOut, const D3DXCOLOR *pC, float c)
{
    assert(pOut != nullptr);
    assert(pC   != nullptr);

    auto vc  = DirectX::XMLoadFloat4((DirectX::XMFLOAT4*)pC);
    auto ret = DirectX::XMColorAdjustContrast(vc, c);
    DirectX::XMStoreFloat4((DirectX::XMFLOAT4*)pOut, ret);
    return pOut;
}


///////////////////////////////////////////////////////////////////////////////
// Misc
///////////////////////////////////////////////////////////////////////////////

float STUB_API D3DXFresnelTerm(float CosTheta, float RefractionIndex)
{
    auto c = DirectX::XMLoadFloat(&CosTheta);
    auto r = DirectX::XMLoadFloat(&RefractionIndex);
    auto ret = DirectX::XMFresnelTerm(c, r);
    return DirectX::XMVectorGetX(ret);
}

///////////////////////////////////////////////////////////////////////////////
// Spherical Harmonics
///////////////////////////////////////////////////////////////////////////////

// Porting From https://github.com/microsoft/DirectXMath/tree/main/SHMath
namespace /* anonymous */ {

const float fExtraNormFac[D3DXSH_MAXORDER] = {
    2.0f * sqrtf(DirectX::XM_PI),
    2.0f / 3.0f * sqrtf(3.0f * DirectX::XM_PI),
    2.0f / 5.0f * sqrtf(5.0f * DirectX::XM_PI),
    2.0f / 7.0f * sqrtf(7.0f * DirectX::XM_PI),
    2.0f / 3.0f * sqrtf(DirectX::XM_PI),
    2.0f / 11.0f * sqrtf(11.0f * DirectX::XM_PI)
};

const float ComputeCapInt_t1 = sqrtf(0.3141593E1f);
const float ComputeCapInt_t5 = sqrtf(3.0f);
const float ComputeCapInt_t11 = sqrtf(5.0f);
const float ComputeCapInt_t18 = sqrtf(7.0f);
const float ComputeCapInt_t32 = sqrtf(11.0f);

inline void ComputeCapInt(const size_t order, float angle, float* pR)
{
    const float t2 = cosf(angle);
    const float t3 = ComputeCapInt_t1 * t2;
    const float t7 = sinf(angle);
    const float t8 = t7 * t7;

    pR[0] = -t3 + ComputeCapInt_t1;
    pR[1] = ComputeCapInt_t5 * ComputeCapInt_t1 * t8 / 2.0f;

    if (order > 2)
    {
        const float t13 = t2 * t2;

        pR[2] = -ComputeCapInt_t11 * ComputeCapInt_t1 * t2 * (t13 - 1.0f) / 2.0f;
        if (order > 3)
        {
            const float t19 = ComputeCapInt_t18 * ComputeCapInt_t1;
            const float t20 = t13 * t13;

            pR[3] = -5.0f / 8.0f * t19 * t20 + 3.0f / 4.0f * t19 * t13 - t19 / 8.0f;
            if (order > 4)
            {
                pR[4] = -3.0f / 8.0f * t3 * (7.0f * t20 - 10.0f * t13 + 3.0f);
                if (order > 5)
                {
                    const float t33 = ComputeCapInt_t32 * ComputeCapInt_t1;
                    pR[5] = -21.0f / 16.0f * t33 * t20 * t13 + 35.0f / 16.0f * t33 * t20 - 15.0f / 16.0f * t33 * t13 + t33 / 16.0f;
                }
            }
        }
    }
}

inline float CosWtInt(const size_t order)
{
    const float fCW0 = 0.25f;
    const float fCW1 = 0.5f;
    const float fCW2 = 5.0f / 16.0f;
    //const float fCW3 = 0.0f;
    const float fCW4 = -3.0f / 32.0f;
    //const float fCW5 = 0.0f;

    // order has to be at least linear...
    float fRet = fCW0 + fCW1;

    if (order > 2) fRet += fCW2;
    if (order > 4) fRet += fCW4;

    // odd degrees >= 3 evaluate to zero integrated against cosine...
    return fRet;
}

const float SHEvalHemisphereLight_fSqrtPi = sqrtf(DirectX::XM_PI);
const float SHEvalHemisphereLight_fSqrtPi3 = sqrtf(DirectX::XM_PI / 3.0f);

using REAL = float;
#define CONSTANT(x) (x ## f)

inline void sh_eval_basis_1(REAL x, REAL y, REAL z, REAL b[4])
{
    /* m=0 */

    // l=0
    const REAL p_0_0 = CONSTANT(0.282094791773878140);
    b[0] = p_0_0; // l=0,m=0
    // l=1
    const REAL p_1_0 = CONSTANT(0.488602511902919920) * z;
    b[2] = p_1_0; // l=1,m=0

    /* m=1 */
    const REAL s1 = y;
    const REAL c1 = x;

    // l=1
    const REAL p_1_1 = CONSTANT(-0.488602511902919920);
    b[1] = p_1_1 * s1; // l=1,m=-1
    b[3] = p_1_1 * c1; // l=1,m=+1
}

inline void sh_eval_basis_2(REAL x, REAL y, REAL z, REAL b[9])
{
    const REAL z2 = z * z;

    /* m=0 */

    // l=0
    const REAL p_0_0 = CONSTANT(0.282094791773878140);
    b[0] = p_0_0; // l=0,m=0
    // l=1
    const REAL p_1_0 = CONSTANT(0.488602511902919920) * z;
    b[2] = p_1_0; // l=1,m=0
    // l=2
    const REAL p_2_0 = CONSTANT(0.946174695757560080) * z2 + CONSTANT(-0.315391565252520050);
    b[6] = p_2_0; // l=2,m=0


    /* m=1 */

    const REAL s1 = y;
    const REAL c1 = x;

    // l=1
    const REAL p_1_1 = CONSTANT(-0.488602511902919920);
    b[1] = p_1_1 * s1; // l=1,m=-1
    b[3] = p_1_1 * c1; // l=1,m=+1
    // l=2
    const REAL p_2_1 = CONSTANT(-1.092548430592079200) * z;
    b[5] = p_2_1 * s1; // l=2,m=-1
    b[7] = p_2_1 * c1; // l=2,m=+1


    /* m=2 */

    const REAL s2 = x * s1 + y * c1;
    const REAL c2 = x * c1 - y * s1;

    // l=2
    const REAL p_2_2 = CONSTANT(0.546274215296039590);
    b[4] = p_2_2 * s2; // l=2,m=-2
    b[8] = p_2_2 * c2; // l=2,m=+2
}

// routine generated programmatically for evaluating SH basis for degree 3
// inputs (x,y,z) are a point on the sphere (i.e., must be unit length)
// output is vector b with SH basis evaluated at (x,y,z).
//
void sh_eval_basis_3(REAL x, REAL y, REAL z, REAL b[16])
{
    const REAL z2 = z * z;


    /* m=0 */

    // l=0
    const REAL p_0_0 = CONSTANT(0.282094791773878140);
    b[0] = p_0_0; // l=0,m=0
    // l=1
    const REAL p_1_0 = CONSTANT(0.488602511902919920) * z;
    b[2] = p_1_0; // l=1,m=0
    // l=2
    const REAL p_2_0 = CONSTANT(0.946174695757560080) * z2 + CONSTANT(-0.315391565252520050);
    b[6] = p_2_0; // l=2,m=0
    // l=3
    const REAL p_3_0 = z * (CONSTANT(1.865881662950577000) * z2 + CONSTANT(-1.119528997770346200));
    b[12] = p_3_0; // l=3,m=0


    /* m=1 */

    const REAL s1 = y;
    const REAL c1 = x;

    // l=1
    const REAL p_1_1 = CONSTANT(-0.488602511902919920);
    b[1] = p_1_1 * s1; // l=1,m=-1
    b[3] = p_1_1 * c1; // l=1,m=+1
    // l=2
    const REAL p_2_1 = CONSTANT(-1.092548430592079200) * z;
    b[5] = p_2_1 * s1; // l=2,m=-1
    b[7] = p_2_1 * c1; // l=2,m=+1
    // l=3
    const REAL p_3_1 = CONSTANT(-2.285228997322328800) * z2 + CONSTANT(0.457045799464465770);
    b[11] = p_3_1 * s1; // l=3,m=-1
    b[13] = p_3_1 * c1; // l=3,m=+1


    /* m=2 */

    const REAL s2 = x * s1 + y * c1;
    const REAL c2 = x * c1 - y * s1;

    // l=2
    const REAL p_2_2 = CONSTANT(0.546274215296039590);
    b[4] = p_2_2 * s2; // l=2,m=-2
    b[8] = p_2_2 * c2; // l=2,m=+2
    // l=3
    const REAL p_3_2 = CONSTANT(1.445305721320277100) * z;
    b[10] = p_3_2 * s2; // l=3,m=-2
    b[14] = p_3_2 * c2; // l=3,m=+2


    /* m=3 */

    const REAL s3 = x * s2 + y * c2;
    const REAL c3 = x * c2 - y * s2;

    // l=3
    const REAL p_3_3 = CONSTANT(-0.590043589926643520);
    b[9] = p_3_3 * s3; // l=3,m=-3
    b[15] = p_3_3 * c3; // l=3,m=+3
}

// routine generated programmatically for evaluating SH basis for degree 4
// inputs (x,y,z) are a point on the sphere (i.e., must be unit length)
// output is vector b with SH basis evaluated at (x,y,z).
//
void sh_eval_basis_4(REAL x, REAL y, REAL z, REAL b[25])
{
    const REAL z2 = z * z;


    /* m=0 */

    // l=0
    const REAL p_0_0 = CONSTANT(0.282094791773878140);
    b[0] = p_0_0; // l=0,m=0
    // l=1
    const REAL p_1_0 = CONSTANT(0.488602511902919920) * z;
    b[2] = p_1_0; // l=1,m=0
    // l=2
    const REAL p_2_0 = CONSTANT(0.946174695757560080) * z2 + CONSTANT(-0.315391565252520050);
    b[6] = p_2_0; // l=2,m=0
    // l=3
    const REAL p_3_0 = z * (CONSTANT(1.865881662950577000) * z2 + CONSTANT(-1.119528997770346200));
    b[12] = p_3_0; // l=3,m=0
    // l=4
    const REAL p_4_0 = CONSTANT(1.984313483298443000) * z * p_3_0 + CONSTANT(-1.006230589874905300) * p_2_0;
    b[20] = p_4_0; // l=4,m=0


    /* m=1 */

    const REAL s1 = y;
    const REAL c1 = x;

    // l=1
    const REAL p_1_1 = CONSTANT(-0.488602511902919920);
    b[1] = p_1_1 * s1; // l=1,m=-1
    b[3] = p_1_1 * c1; // l=1,m=+1
    // l=2
    const REAL p_2_1 = CONSTANT(-1.092548430592079200) * z;
    b[5] = p_2_1 * s1; // l=2,m=-1
    b[7] = p_2_1 * c1; // l=2,m=+1
    // l=3
    const REAL p_3_1 = CONSTANT(-2.285228997322328800) * z2 + CONSTANT(0.457045799464465770);
    b[11] = p_3_1 * s1; // l=3,m=-1
    b[13] = p_3_1 * c1; // l=3,m=+1
    // l=4
    const REAL p_4_1 = z * (CONSTANT(-4.683325804901024000) * z2 + CONSTANT(2.007139630671867200));
    b[19] = p_4_1 * s1; // l=4,m=-1
    b[21] = p_4_1 * c1; // l=4,m=+1


    /* m=2 */

    const REAL s2 = x * s1 + y * c1;
    const REAL c2 = x * c1 - y * s1;

    // l=2
    const REAL p_2_2 = CONSTANT(0.546274215296039590);
    b[4] = p_2_2 * s2; // l=2,m=-2
    b[8] = p_2_2 * c2; // l=2,m=+2
    // l=3
    const REAL p_3_2 = CONSTANT(1.445305721320277100) * z;
    b[10] = p_3_2 * s2; // l=3,m=-2
    b[14] = p_3_2 * c2; // l=3,m=+2
    // l=4
    const REAL p_4_2 = CONSTANT(3.311611435151459800) * z2 + CONSTANT(-0.473087347878779980);
    b[18] = p_4_2 * s2; // l=4,m=-2
    b[22] = p_4_2 * c2; // l=4,m=+2


    /* m=3 */

    const REAL s3 = x * s2 + y * c2;
    const REAL c3 = x * c2 - y * s2;

    // l=3
    const REAL p_3_3 = CONSTANT(-0.590043589926643520);
    b[9] = p_3_3 * s3; // l=3,m=-3
    b[15] = p_3_3 * c3; // l=3,m=+3
    // l=4
    const REAL p_4_3 = CONSTANT(-1.770130769779930200) * z;
    b[17] = p_4_3 * s3; // l=4,m=-3
    b[23] = p_4_3 * c3; // l=4,m=+3


    /* m=4 */

    const REAL s4 = x * s3 + y * c3;
    const REAL c4 = x * c3 - y * s3;

    // l=4
    const REAL p_4_4 = CONSTANT(0.625835735449176030);
    b[16] = p_4_4 * s4; // l=4,m=-4
    b[24] = p_4_4 * c4; // l=4,m=+4
}

// routine generated programmatically for evaluating SH basis for degree 5
// inputs (x,y,z) are a point on the sphere (i.e., must be unit length)
// output is vector b with SH basis evaluated at (x,y,z).
//
void sh_eval_basis_5(REAL x, REAL y, REAL z, REAL b[36])
{
    const REAL z2 = z * z;


    /* m=0 */

    // l=0
    const REAL p_0_0 = CONSTANT(0.282094791773878140);
    b[0] = p_0_0; // l=0,m=0
    // l=1
    const REAL p_1_0 = CONSTANT(0.488602511902919920) * z;
    b[2] = p_1_0; // l=1,m=0
    // l=2
    const REAL p_2_0 = CONSTANT(0.946174695757560080) * z2 + CONSTANT(-0.315391565252520050);
    b[6] = p_2_0; // l=2,m=0
    // l=3
    const REAL p_3_0 = z * (CONSTANT(1.865881662950577000) * z2 + CONSTANT(-1.119528997770346200));
    b[12] = p_3_0; // l=3,m=0
    // l=4
    const REAL p_4_0 = CONSTANT(1.984313483298443000) * z * p_3_0 + CONSTANT(-1.006230589874905300) * p_2_0;
    b[20] = p_4_0; // l=4,m=0
    // l=5
    const REAL p_5_0 = CONSTANT(1.989974874213239700) * z * p_4_0 + CONSTANT(-1.002853072844814000) * p_3_0;
    b[30] = p_5_0; // l=5,m=0


    /* m=1 */

    const REAL s1 = y;
    const REAL c1 = x;

    // l=1
    const REAL p_1_1 = CONSTANT(-0.488602511902919920);
    b[1] = p_1_1 * s1; // l=1,m=-1
    b[3] = p_1_1 * c1; // l=1,m=+1
    // l=2
    const REAL p_2_1 = CONSTANT(-1.092548430592079200) * z;
    b[5] = p_2_1 * s1; // l=2,m=-1
    b[7] = p_2_1 * c1; // l=2,m=+1
    // l=3
    const REAL p_3_1 = CONSTANT(-2.285228997322328800) * z2 + CONSTANT(0.457045799464465770);
    b[11] = p_3_1 * s1; // l=3,m=-1
    b[13] = p_3_1 * c1; // l=3,m=+1
    // l=4
    const REAL p_4_1 = z * (CONSTANT(-4.683325804901024000) * z2 + CONSTANT(2.007139630671867200));
    b[19] = p_4_1 * s1; // l=4,m=-1
    b[21] = p_4_1 * c1; // l=4,m=+1
    // l=5
    const REAL p_5_1 = CONSTANT(2.031009601158990200) * z * p_4_1 + CONSTANT(-0.991031208965114650) * p_3_1;
    b[29] = p_5_1 * s1; // l=5,m=-1
    b[31] = p_5_1 * c1; // l=5,m=+1


    /* m=2 */

    const REAL s2 = x * s1 + y * c1;
    const REAL c2 = x * c1 - y * s1;

    // l=2
    const REAL p_2_2 = CONSTANT(0.546274215296039590);
    b[4] = p_2_2 * s2; // l=2,m=-2
    b[8] = p_2_2 * c2; // l=2,m=+2
    // l=3
    const REAL p_3_2 = CONSTANT(1.445305721320277100) * z;
    b[10] = p_3_2 * s2; // l=3,m=-2
    b[14] = p_3_2 * c2; // l=3,m=+2
    // l=4
    const REAL p_4_2 = CONSTANT(3.311611435151459800) * z2 + CONSTANT(-0.473087347878779980);
    b[18] = p_4_2 * s2; // l=4,m=-2
    b[22] = p_4_2 * c2; // l=4,m=+2
    // l=5
    const REAL p_5_2 = z * (CONSTANT(7.190305177459987500) * z2 + CONSTANT(-2.396768392486662100));
    b[28] = p_5_2 * s2; // l=5,m=-2
    b[32] = p_5_2 * c2; // l=5,m=+2


    /* m=3 */

    const REAL s3 = x * s2 + y * c2;
    const REAL c3 = x * c2 - y * s2;

    // l=3
    const REAL p_3_3 = CONSTANT(-0.590043589926643520);
    b[9] = p_3_3 * s3; // l=3,m=-3
    b[15] = p_3_3 * c3; // l=3,m=+3
    // l=4
    const REAL p_4_3 = CONSTANT(-1.770130769779930200) * z;
    b[17] = p_4_3 * s3; // l=4,m=-3
    b[23] = p_4_3 * c3; // l=4,m=+3
    // l=5
    const REAL p_5_3 = CONSTANT(-4.403144694917253700) * z2 + CONSTANT(0.489238299435250430);
    b[27] = p_5_3 * s3; // l=5,m=-3
    b[33] = p_5_3 * c3; // l=5,m=+3


    /* m=4 */

    const REAL s4 = x * s3 + y * c3;
    const REAL c4 = x * c3 - y * s3;

    // l=4
    const REAL p_4_4 = CONSTANT(0.625835735449176030);
    b[16] = p_4_4 * s4; // l=4,m=-4
    b[24] = p_4_4 * c4; // l=4,m=+4
    // l=5
    const REAL p_5_4 = CONSTANT(2.075662314881041100) * z;
    b[26] = p_5_4 * s4; // l=5,m=-4
    b[34] = p_5_4 * c4; // l=5,m=+4


    /* m=5 */

    const REAL s5 = x * s4 + y * c4;
    const REAL c5 = x * c4 - y * s4;

    // l=5
    const REAL p_5_5 = CONSTANT(-0.656382056840170150);
    b[25] = p_5_5 * s5; // l=5,m=-5
    b[35] = p_5_5 * c5; // l=5,m=+5
}

const REAL M_PIjs = (REAL)(4.0 * atan(1.0));
const REAL maxang = (REAL)(M_PIjs / 2);
const int NSH0 = 1;
const int NSH1 = 4;
const int NSH2 = 9;
const int NSH3 = 16;
const int NSH4 = 25;
const int NSH5 = 36;
const int NSH6 = 49;
const int NSH7 = 64;
const int NSH8 = 81;
const int NSH9 = 100;
const int NL0 = 1;
const int NL1 = 3;
const int NL2 = 5;
const int NL3 = 7;
const int NL4 = 9;
const int NL5 = 11;
const int NL6 = 13;
const int NL7 = 15;
const int NL8 = 17;
const int NL9 = 19;

inline void rot(REAL ct, REAL st, REAL x, REAL y, REAL& xout, REAL& yout)
{
    xout = x * ct - y * st;
    yout = y * ct + x * st;
}

inline void rot_inv(REAL ct, REAL st, REAL x, REAL y, REAL& xout, REAL& yout)
{
    xout = x * ct + y * st;
    yout = y * ct - x * st;
}

inline void rot_1(REAL ct, REAL st, REAL ctm[1], REAL stm[1])
{
    ctm[0] = ct;
    stm[0] = st;
}

inline void rot_2(REAL ct, REAL st, REAL ctm[2], REAL stm[2])
{
    REAL ct2 = CONSTANT(2.0) * ct;
    ctm[0] = ct;
    stm[0] = st;
    ctm[1] = ct2 * ct - CONSTANT(1.0);
    stm[1] = ct2 * st;
}

inline void rot_3(REAL ct, REAL st, REAL ctm[3], REAL stm[3])
{
    REAL ct2 = CONSTANT(2.0) * ct;
    ctm[0] = ct;
    stm[0] = st;
    ctm[1] = ct2 * ct - CONSTANT(1.0);
    stm[1] = ct2 * st;
    ctm[2] = ct2 * ctm[1] - ct;
    stm[2] = ct2 * stm[1] - st;
}

inline void rot_4(REAL ct, REAL st, REAL ctm[4], REAL stm[4])
{
    REAL ct2 = CONSTANT(2.0) * ct;
    ctm[0] = ct;
    stm[0] = st;
    ctm[1] = ct2 * ct - CONSTANT(1.0);
    stm[1] = ct2 * st;
    ctm[2] = ct2 * ctm[1] - ct;
    stm[2] = ct2 * stm[1] - st;
    ctm[3] = ct2 * ctm[2] - ctm[1];
    stm[3] = ct2 * stm[2] - stm[1];
}

inline void rot_5(REAL ct, REAL st, REAL ctm[5], REAL stm[5])
{
    REAL ct2 = CONSTANT(2.0) * ct;
    ctm[0] = ct;
    stm[0] = st;
    ctm[1] = ct2 * ct - CONSTANT(1.0);
    stm[1] = ct2 * st;
    ctm[2] = ct2 * ctm[1] - ct;
    stm[2] = ct2 * stm[1] - st;
    ctm[3] = ct2 * ctm[2] - ctm[1];
    stm[3] = ct2 * stm[2] - stm[1];
    ctm[4] = ct2 * ctm[3] - ctm[2];
    stm[4] = ct2 * stm[3] - stm[2];
}

inline void sh_rotz_1(REAL ctm[1], REAL stm[1], REAL y[NL1], REAL yr[NL1])
{
    yr[1] = y[1];
    rot_inv(ctm[0], stm[0], y[0], y[2], yr[0], yr[2]);
}

inline void sh_rotz_2(REAL ctm[2], REAL stm[2], REAL y[NL2], REAL yr[NL2])
{
    yr[2] = y[2];
    rot_inv(ctm[0], stm[0], y[1], y[3], yr[1], yr[3]);
    rot_inv(ctm[1], stm[1], y[0], y[4], yr[0], yr[4]);
}

inline void sh_rotz_3(REAL ctm[3], REAL stm[3], REAL y[NL3], REAL yr[NL3])
{
    yr[3] = y[3];
    rot_inv(ctm[0], stm[0], y[2], y[4], yr[2], yr[4]);
    rot_inv(ctm[1], stm[1], y[1], y[5], yr[1], yr[5]);
    rot_inv(ctm[2], stm[2], y[0], y[6], yr[0], yr[6]);
}

inline void sh_rotz_4(REAL ctm[4], REAL stm[4], REAL y[NL4], REAL yr[NL4])
{
    yr[4] = y[4];
    rot_inv(ctm[0], stm[0], y[3], y[5], yr[3], yr[5]);
    rot_inv(ctm[1], stm[1], y[2], y[6], yr[2], yr[6]);
    rot_inv(ctm[2], stm[2], y[1], y[7], yr[1], yr[7]);
    rot_inv(ctm[3], stm[3], y[0], y[8], yr[0], yr[8]);
}

inline void sh_rotz_5(REAL ctm[5], REAL stm[5], REAL y[NL5], REAL yr[NL5])
{
    yr[5] = y[5];
    rot_inv(ctm[0], stm[0], y[4], y[6], yr[4], yr[6]);
    rot_inv(ctm[1], stm[1], y[3], y[7], yr[3], yr[7]);
    rot_inv(ctm[2], stm[2], y[2], y[8], yr[2], yr[8]);
    rot_inv(ctm[3], stm[3], y[1], y[9], yr[1], yr[9]);
    rot_inv(ctm[4], stm[4], y[0], y[10], yr[0], yr[10]);
}

// rotation code generated programmatically by rotatex (2000x4000 samples, eps=1e-008)

const REAL fx_1_001 = (REAL)(sqrt(1.0) / 1.0); // 1
const REAL fx_1_002 = (REAL)(-sqrt(1.0) / 1.0); // -1.00000030843

inline void sh_rotx90_1(REAL y[], REAL yr[])
{
    yr[0] = fx_1_001 * y[1];
    yr[1] = fx_1_002 * y[0];
    yr[2] = fx_1_001 * y[2];
};

inline void sh_rotx90_inv_1(REAL y[], REAL yr[])
{
    yr[0] = fx_1_002 * y[1];
    yr[1] = fx_1_001 * y[0];
    yr[2] = fx_1_001 * y[2];
}

const REAL fx_2_001 = (REAL)(sqrt(4.0) / 2.0); // 1
const REAL fx_2_002 = (REAL)(-sqrt(4.0) / 2.0); // -1
const REAL fx_2_003 = (REAL)(-sqrt(1.0) / 2.0); // -0.500000257021
const REAL fx_2_004 = (REAL)(-sqrt(3.0) / 2.0); // -0.866025848959
const REAL fx_2_005 = (REAL)(sqrt(1.0) / 2.0); // 0.5

inline void sh_rotx90_2(REAL y[], REAL yr[])
{
    yr[0] = fx_2_001 * y[3];
    yr[1] = fx_2_002 * y[1];
    yr[2] = fx_2_003 * y[2] + fx_2_004 * y[4];
    yr[3] = fx_2_002 * y[0];
    yr[4] = fx_2_004 * y[2] + fx_2_005 * y[4];
};

inline void sh_rotx90_inv_2(REAL y[], REAL yr[])
{
    yr[0] = fx_2_002 * y[3];
    yr[1] = fx_2_002 * y[1];
    yr[2] = fx_2_003 * y[2] + fx_2_004 * y[4];
    yr[3] = fx_2_001 * y[0];
    yr[4] = fx_2_004 * y[2] + fx_2_005 * y[4];
}

const REAL fx_3_001 = (REAL)(-sqrt(10.0) / 4.0); // -0.790569415042
const REAL fx_3_002 = (REAL)(sqrt(6.0) / 4.0); // 0.612372435696
const REAL fx_3_003 = (REAL)(-sqrt(16.0) / 4.0); // -1
const REAL fx_3_004 = (REAL)(-sqrt(6.0) / 4.0); // -0.612372435695
const REAL fx_3_005 = (REAL)(-sqrt(1.0) / 4.0); // -0.25
const REAL fx_3_006 = (REAL)(-sqrt(15.0) / 4.0); // -0.968245836551
const REAL fx_3_007 = (REAL)(sqrt(1.0) / 4.0); // 0.25
const REAL fx_3_008 = (REAL)(sqrt(10.0) / 4.0); // 0.790569983984

inline void sh_rotx90_3(REAL y[], REAL yr[])
{
    yr[0] = fx_3_001 * y[3] + fx_3_002 * y[5];
    yr[1] = fx_3_003 * y[1];
    yr[2] = fx_3_004 * y[3] + fx_3_001 * y[5];
    yr[3] = fx_3_008 * y[0] + fx_3_002 * y[2];
    yr[4] = fx_3_005 * y[4] + fx_3_006 * y[6];
    yr[5] = fx_3_004 * y[0] - fx_3_001 * y[2];
    yr[6] = fx_3_006 * y[4] + fx_3_007 * y[6];
};

inline void sh_rotx90_inv_3(REAL y[], REAL yr[])
{
    yr[0] = fx_3_008 * y[3] + fx_3_004 * y[5];
    yr[1] = fx_3_003 * y[1];
    yr[2] = fx_3_002 * y[3] - fx_3_001 * y[5];
    yr[3] = fx_3_001 * y[0] + fx_3_004 * y[2];
    yr[4] = fx_3_005 * y[4] + fx_3_006 * y[6];
    yr[5] = fx_3_002 * y[0] + fx_3_001 * y[2];
    yr[6] = fx_3_006 * y[4] + fx_3_007 * y[6];
}

const REAL fx_4_001 = (REAL)(-sqrt(56.0) / 8.0); // -0.935414346694
const REAL fx_4_002 = (REAL)(sqrt(8.0) / 8.0); //  0.353553390593
const REAL fx_4_003 = (REAL)(-sqrt(36.0) / 8.0); // -0.75
const REAL fx_4_004 = (REAL)(sqrt(28.0) / 8.0); //  0.661437827766
const REAL fx_4_005 = (REAL)(-sqrt(8.0) / 8.0); // -0.353553390593
const REAL fx_4_006 = (REAL)(sqrt(36.0) / 8.0); //  0.749999999999
const REAL fx_4_007 = (REAL)(sqrt(9.0) / 8.0); //  0.37500034698
const REAL fx_4_008 = (REAL)(sqrt(20.0) / 8.0); //  0.559017511622
const REAL fx_4_009 = (REAL)(sqrt(35.0) / 8.0); //  0.739510657141
const REAL fx_4_010 = (REAL)(sqrt(16.0) / 8.0); //  0.5
const REAL fx_4_011 = (REAL)(-sqrt(28.0) / 8.0); // -0.661437827766
const REAL fx_4_012 = (REAL)(sqrt(1.0) / 8.0); //  0.125
const REAL fx_4_013 = (REAL)(sqrt(56.0) / 8.0); //  0.935414346692

inline void sh_rotx90_4(REAL y[], REAL yr[])
{
    yr[0] = fx_4_001 * y[5] + fx_4_002 * y[7];
    yr[1] = fx_4_003 * y[1] + fx_4_004 * y[3];
    yr[2] = fx_4_005 * y[5] + fx_4_001 * y[7];
    yr[3] = fx_4_004 * y[1] + fx_4_006 * y[3];
    yr[4] = fx_4_007 * y[4] + fx_4_008 * y[6] + fx_4_009 * y[8];
    yr[5] = fx_4_013 * y[0] + fx_4_002 * y[2];
    yr[6] = fx_4_008 * y[4] + fx_4_010 * y[6] + fx_4_011 * y[8];
    yr[7] = fx_4_005 * y[0] - fx_4_001 * y[2];
    yr[8] = fx_4_009 * y[4] + fx_4_011 * y[6] + fx_4_012 * y[8];
};

inline void sh_rotx90_inv_4(REAL y[], REAL yr[])
{
    yr[0] = fx_4_013 * y[5] + fx_4_005 * y[7];
    yr[1] = fx_4_003 * y[1] + fx_4_004 * y[3];
    yr[2] = fx_4_002 * y[5] - fx_4_001 * y[7];
    yr[3] = fx_4_004 * y[1] + fx_4_006 * y[3];
    yr[4] = fx_4_007 * y[4] + fx_4_008 * y[6] + fx_4_009 * y[8];
    yr[5] = fx_4_001 * y[0] + fx_4_005 * y[2];
    yr[6] = fx_4_008 * y[4] + fx_4_010 * y[6] + fx_4_011 * y[8];
    yr[7] = fx_4_002 * y[0] + fx_4_001 * y[2];
    yr[8] = fx_4_009 * y[4] + fx_4_011 * y[6] + fx_4_012 * y[8];
}

const REAL fx_5_001 = (REAL)(sqrt(126.0) / 16.0); //  0.70156076002
const REAL fx_5_002 = (REAL)(-sqrt(120.0) / 16.0); // -0.684653196882
const REAL fx_5_003 = (REAL)(sqrt(10.0) / 16.0); //  0.197642353761
const REAL fx_5_004 = (REAL)(-sqrt(64.0) / 16.0); // -0.5
const REAL fx_5_005 = (REAL)(sqrt(192.0) / 16.0); //  0.866025403784
const REAL fx_5_006 = (REAL)(sqrt(70.0) / 16.0); //  0.522912516584
const REAL fx_5_007 = (REAL)(sqrt(24.0) / 16.0); //  0.306186217848
const REAL fx_5_008 = (REAL)(-sqrt(162.0) / 16.0); // -0.795495128835
const REAL fx_5_009 = (REAL)(sqrt(64.0) / 16.0); //  0.5
const REAL fx_5_010 = (REAL)(sqrt(60.0) / 16.0); //  0.484122918274
const REAL fx_5_011 = (REAL)(sqrt(112.0) / 16.0); //  0.661437827763
const REAL fx_5_012 = (REAL)(sqrt(84.0) / 16.0); //  0.572821961867
const REAL fx_5_013 = (REAL)(sqrt(4.0) / 16.0); //  0.125
const REAL fx_5_014 = (REAL)(sqrt(42.0) / 16.0); //  0.405046293649
const REAL fx_5_015 = (REAL)(sqrt(210.0) / 16.0); //  0.905711046633
const REAL fx_5_016 = (REAL)(sqrt(169.0) / 16.0); //  0.8125
const REAL fx_5_017 = (REAL)(-sqrt(45.0) / 16.0); // -0.419262745781
const REAL fx_5_018 = (REAL)(sqrt(1.0) / 16.0); //  0.0625
const REAL fx_5_019 = (REAL)(-sqrt(126.0) / 16.0); // -0.701561553415
const REAL fx_5_020 = (REAL)(sqrt(120.0) / 16.0); //  0.684653196881
const REAL fx_5_021 = (REAL)(-sqrt(10.0) / 16.0); // -0.197642353761
const REAL fx_5_022 = (REAL)(-sqrt(70.0) / 16.0); // -0.522913107945
const REAL fx_5_023 = (REAL)(-sqrt(60.0) / 16.0); // -0.48412346577

inline void sh_rotx90_5(REAL y[], REAL yr[])
{
    yr[0] = fx_5_001 * y[5] + fx_5_002 * y[7] + fx_5_003 * y[9];
    yr[1] = fx_5_004 * y[1] + fx_5_005 * y[3];
    yr[2] = fx_5_006 * y[5] + fx_5_007 * y[7] + fx_5_008 * y[9];
    yr[3] = fx_5_005 * y[1] + fx_5_009 * y[3];
    yr[4] = fx_5_010 * y[5] + fx_5_011 * y[7] + fx_5_012 * y[9];
    yr[5] = fx_5_019 * y[0] + fx_5_022 * y[2] + fx_5_023 * y[4];
    yr[6] = fx_5_013 * y[6] + fx_5_014 * y[8] + fx_5_015 * y[10];
    yr[7] = fx_5_020 * y[0] - fx_5_007 * y[2] - fx_5_011 * y[4];
    yr[8] = fx_5_014 * y[6] + fx_5_016 * y[8] + fx_5_017 * y[10];
    yr[9] = fx_5_021 * y[0] - fx_5_008 * y[2] - fx_5_012 * y[4];
    yr[10] = fx_5_015 * y[6] + fx_5_017 * y[8] + fx_5_018 * y[10];
};

inline void sh_rotx90_inv_5(REAL y[], REAL yr[])
{
    yr[0] = fx_5_019 * y[5] + fx_5_020 * y[7] + fx_5_021 * y[9];
    yr[1] = fx_5_004 * y[1] + fx_5_005 * y[3];
    yr[2] = fx_5_022 * y[5] - fx_5_007 * y[7] - fx_5_008 * y[9];
    yr[3] = fx_5_005 * y[1] + fx_5_009 * y[3];
    yr[4] = fx_5_023 * y[5] - fx_5_011 * y[7] - fx_5_012 * y[9];
    yr[5] = fx_5_001 * y[0] + fx_5_006 * y[2] + fx_5_010 * y[4];
    yr[6] = fx_5_013 * y[6] + fx_5_014 * y[8] + fx_5_015 * y[10];
    yr[7] = fx_5_002 * y[0] + fx_5_007 * y[2] + fx_5_011 * y[4];
    yr[8] = fx_5_014 * y[6] + fx_5_016 * y[8] + fx_5_017 * y[10];
    yr[9] = fx_5_003 * y[0] + fx_5_008 * y[2] + fx_5_012 * y[4];
    yr[10] = fx_5_015 * y[6] + fx_5_017 * y[8] + fx_5_018 * y[10];
}

inline void sh_rot_1(REAL m[3 * 3], REAL y[NL1], REAL yr[NL1])
{
    REAL yr0 = m[4] * y[0] - m[5] * y[1] + m[3] * y[2];
    REAL yr1 = m[8] * y[1] - m[7] * y[0] - m[6] * y[2];
    REAL yr2 = m[1] * y[0] - m[2] * y[1] + m[0] * y[2];

    yr[0] = yr0;
    yr[1] = yr1;
    yr[2] = yr2;
}

inline void sh_roty_1(REAL ctm[1], REAL stm[1], REAL y[NL1], REAL yr[NL1])
{
    yr[0] = y[0];
    rot_inv(ctm[0], stm[0], y[1], y[2], yr[1], yr[2]);
}

inline void sh_roty_2(REAL ctm[2], REAL stm[2], REAL y[NL2], REAL yr[NL2])
{
    REAL ytmp[NL2];
    sh_rotx90_2(y, yr);
    sh_rotz_2(ctm, stm, yr, ytmp);
    sh_rotx90_inv_2(ytmp, yr);
}

inline void sh_roty_3(REAL ctm[3], REAL stm[3], REAL y[NL3], REAL yr[NL3])
{
    REAL ytmp[NL3];
    sh_rotx90_3(y, yr);
    sh_rotz_3(ctm, stm, yr, ytmp);
    sh_rotx90_inv_3(ytmp, yr);
}

inline void sh_roty_4(REAL ctm[4], REAL stm[4], REAL y[NL4], REAL yr[NL4])
{
    REAL ytmp[NL4];
    sh_rotx90_4(y, yr);
    sh_rotz_4(ctm, stm, yr, ytmp);
    sh_rotx90_inv_4(ytmp, yr);
}

inline void sh_roty_5(REAL ctm[5], REAL stm[5], REAL y[NL5], REAL yr[NL5])
{
    REAL ytmp[NL5];
    sh_rotx90_5(y, yr);
    sh_rotz_5(ctm, stm, yr, ytmp);
    sh_rotx90_inv_5(ytmp, yr);
}

#define ROT_TOL CONSTANT(1e-4)

/*
Finds cosine,sine pairs for zyz rotation (i.e. rotation R_z2 R_y R_z1 v).
The rotation is one which maps mx to (1,0,0) and mz to (0,0,1).
*/
inline void zyz(REAL m[3 * 3], REAL& zc1, REAL& zs1, REAL& yc, REAL& ys, REAL& zc2, REAL& zs2)
{
    REAL cz = m[8];

    // rotate so that (cx,cy,0) aligns to (1,0,0)
    REAL cxylen = (REAL)sqrtf(1.0f - cz * cz);
    if (cxylen >= ROT_TOL)
    {
        // if above is a NaN, will do the correct thing
        yc = cz;
        ys = cxylen;
        REAL len67inv = 1.0f / sqrtf(m[6] * m[6] + m[7] * m[7]);
        zc1 = -m[6] * len67inv;
        zs1 = m[7] * len67inv;
        REAL len25inv = 1.0f / sqrtf(m[2] * m[2] + m[5] * m[5]);
        zc2 = m[2] * len25inv;
        zs2 = m[5] * len25inv;
    }
    else {  // m[6],m[7],m[8] already aligned to (0,0,1)
        zc1 = 1.0; zs1 = 0.0;        // identity
        yc = cz; ys = 0.0;           // identity
        zc2 = m[0] * cz; zs2 = -m[1];  // align x axis (mx[0],mx[1],0) to (1,0,0)
    }
}

inline void sh_rotzyz_2(REAL zc1m[2], REAL zs1m[2], REAL ycm[2], REAL ysm[2], REAL zc2m[2], REAL zs2m[2], REAL y[NL2], REAL yr[NL2])
{
    REAL ytmp[NL2];
    sh_rotz_2(zc1m, zs1m, y, yr);
    sh_roty_2(ycm, ysm, yr, ytmp);
    sh_rotz_2(zc2m, zs2m, ytmp, yr);
}

inline void sh_rotzyz_3(REAL zc1m[3], REAL zs1m[3], REAL ycm[3], REAL ysm[3], REAL zc2m[3], REAL zs2m[3], REAL y[NL3], REAL yr[NL3])
{
    REAL ytmp[NL3];
    sh_rotz_3(zc1m, zs1m, y, yr);
    sh_roty_3(ycm, ysm, yr, ytmp);
    sh_rotz_3(zc2m, zs2m, ytmp, yr);
}

inline void sh_rotzyz_4(REAL zc1m[4], REAL zs1m[4], REAL ycm[4], REAL ysm[4], REAL zc2m[4], REAL zs2m[4], REAL y[NL4], REAL yr[NL4])
{
    REAL ytmp[NL4];
    sh_rotz_4(zc1m, zs1m, y, yr);
    sh_roty_4(ycm, ysm, yr, ytmp);
    sh_rotz_4(zc2m, zs2m, ytmp, yr);
}

inline void sh_rotzyz_5(REAL zc1m[5], REAL zs1m[5], REAL ycm[5], REAL ysm[5], REAL zc2m[5], REAL zs2m[5], REAL y[NL5], REAL yr[NL5])
{
    REAL ytmp[NL5];
    sh_rotz_5(zc1m, zs1m, y, yr);
    sh_roty_5(ycm, ysm, yr, ytmp);
    sh_rotz_5(zc2m, zs2m, ytmp, yr);
}

inline void sh3_rot(REAL m[3 * 3], REAL zc1, REAL zs1, REAL yc, REAL ys, REAL zc2, REAL zs2, REAL y[NSH3], REAL yr[NSH3])
{
    REAL zc1m[3], zs1m[3];
    rot_3(zc1, zs1, zc1m, zs1m);
    REAL ycm[3], ysm[3];
    rot_3(yc, ys, ycm, ysm);
    REAL zc2m[3], zs2m[3];
    rot_3(zc2, zs2, zc2m, zs2m);

    yr[0] = y[0];
    sh_rot_1(m, y + NSH0, yr + NSH0);
    sh_rotzyz_2(zc1m, zs1m, ycm, ysm, zc2m, zs2m, y + NSH1, yr + NSH1);
    sh_rotzyz_3(zc1m, zs1m, ycm, ysm, zc2m, zs2m, y + NSH2, yr + NSH2);
}

inline void sh4_rot(REAL m[3 * 3], REAL zc1, REAL zs1, REAL yc, REAL ys, REAL zc2, REAL zs2, REAL y[NSH4], REAL yr[NSH4])
{
    REAL zc1m[4], zs1m[4];
    rot_4(zc1, zs1, zc1m, zs1m);
    REAL ycm[4], ysm[4];
    rot_4(yc, ys, ycm, ysm);
    REAL zc2m[4], zs2m[4];
    rot_4(zc2, zs2, zc2m, zs2m);

    yr[0] = y[0];
    sh_rot_1(m, y + NSH0, yr + NSH0);
    sh_rotzyz_2(zc1m, zs1m, ycm, ysm, zc2m, zs2m, y + NSH1, yr + NSH1);
    sh_rotzyz_3(zc1m, zs1m, ycm, ysm, zc2m, zs2m, y + NSH2, yr + NSH2);
    sh_rotzyz_4(zc1m, zs1m, ycm, ysm, zc2m, zs2m, y + NSH3, yr + NSH3);
}

inline void sh5_rot(REAL m[3 * 3], REAL zc1, REAL zs1, REAL yc, REAL ys, REAL zc2, REAL zs2, REAL y[NSH5], REAL yr[NSH5])
{
    REAL zc1m[5], zs1m[5];
    rot_5(zc1, zs1, zc1m, zs1m);
    REAL ycm[5], ysm[5];
    rot_5(yc, ys, ycm, ysm);
    REAL zc2m[5], zs2m[5];
    rot_5(zc2, zs2, zc2m, zs2m);

    yr[0] = y[0];
    sh_rot_1(m, y + NSH0, yr + NSH0);
    sh_rotzyz_2(zc1m, zs1m, ycm, ysm, zc2m, zs2m, y + NSH1, yr + NSH1);
    sh_rotzyz_3(zc1m, zs1m, ycm, ysm, zc2m, zs2m, y + NSH2, yr + NSH2);
    sh_rotzyz_4(zc1m, zs1m, ycm, ysm, zc2m, zs2m, y + NSH3, yr + NSH3);
    sh_rotzyz_5(zc1m, zs1m, ycm, ysm, zc2m, zs2m, y + NSH4, yr + NSH4);
}

inline void sh1_rot(REAL m[3 * 3], REAL y[NSH1], REAL yr[NSH1])
{
    yr[0] = y[0];
    sh_rot_1(m, y + NSH0, yr + NSH0);
}

inline void sh3_rot(REAL m[3 * 3], REAL y[NSH3], REAL yr[NSH3])
{
    REAL zc1, zs1, yc, ys, zc2, zs2;
    zyz(m, zc1, zs1, yc, ys, zc2, zs2);
    sh3_rot(m, zc1, zs1, yc, ys, zc2, zs2, y, yr);
}

inline void sh4_rot(REAL m[3 * 3], REAL y[NSH4], REAL yr[NSH4])
{
    REAL zc1, zs1, yc, ys, zc2, zs2;
    zyz(m, zc1, zs1, yc, ys, zc2, zs2);
    sh4_rot(m, zc1, zs1, yc, ys, zc2, zs2, y, yr);
}

inline void sh5_rot(REAL m[3 * 3], REAL y[NSH5], REAL yr[NSH5])
{
    REAL zc1, zs1, yc, ys, zc2, zs2;
    zyz(m, zc1, zs1, yc, ys, zc2, zs2);
    sh5_rot(m, zc1, zs1, yc, ys, zc2, zs2, y, yr);
}

// simple matrix vector multiply for a square matrix (only used by ZRotation)
inline void SimpMatMul(size_t dim, const float* matrix, const float* input, float* result)
{
    for (size_t iR = 0; iR < dim; ++iR)
    {
        result[iR + 0] = matrix[iR * dim + 0] * input[0];
        for (size_t iC = 1; iC < dim; ++iC)
        {
            result[iR] += matrix[iR * dim + iC] * input[iC];
        }
    }
}

}; // anonymous namespace

float* STUB_API D3DXSHEvalDirection(float* pOut, uint32_t Order, const D3DXVECTOR3* pDir)
{
    if (!pOut || !pDir)
        return nullptr;

    const float fX = pDir->x;
    const float fY = pDir->y;
    const float fZ = pDir->z;

    switch (Order)
    {
    case 2:
        sh_eval_basis_1(fX, fY, fZ, pOut);
        break;

    case 3:
        sh_eval_basis_2(fX, fY, fZ, pOut);
        break;

    case 4:
        sh_eval_basis_3(fX, fY, fZ, pOut);
        break;

    case 5:
        sh_eval_basis_4(fX, fY, fZ, pOut);
        break;

    case 6:
        sh_eval_basis_5(fX, fY, fZ, pOut);
        break;

    default:
        assert(Order < D3DXSH_MINORDER || Order > D3DXSH_MAXORDER);
        return nullptr;
    }

    return pOut;
}

float* STUB_API D3DXSHRotate(float* pOut, uint32_t Order, const D3DXMATRIX* pMatrix, const float* pIn)
{
    if (!pOut || !pIn || !pMatrix)
        return nullptr;

    if (pOut == pIn)
        return nullptr;

    float mRot[3 * 3];
    const float r00 = mRot[0 * 3 + 0] = pMatrix->_11;
    const float r10 = mRot[1 * 3 + 0] = pMatrix->_12;
    const float r20 = mRot[2 * 3 + 0] = pMatrix->_13;

    const float r01 = mRot[0 * 3 + 1] = pMatrix->_21;
    const float r11 = mRot[1 * 3 + 1] = pMatrix->_22;
    const float r21 = mRot[2 * 3 + 1] = pMatrix->_23;

    const float r02 = mRot[0 * 3 + 2] = pMatrix->_31;
    const float r12 = mRot[1 * 3 + 2] = pMatrix->_32;
    const float r22 = mRot[2 * 3 + 2] = pMatrix->_33;

    pOut[0] = pIn[0]; // rotate the constant term

    switch (Order)
    {
    case 2:
    {
        // do linear by hand...

        pOut[1] = r11 * pIn[1] - r12 * pIn[2] + r10 * pIn[3];
        pOut[2] = -r21 * pIn[1] + r22 * pIn[2] - r20 * pIn[3];
        pOut[3] = r01 * pIn[1] - r02 * pIn[2] + r00 * pIn[3];
    }
    break;

    case 3:
    {
        float R[25];
        // do linear by hand...

        pOut[1] = r11 * pIn[1] - r12 * pIn[2] + r10 * pIn[3];
        pOut[2] = -r21 * pIn[1] + r22 * pIn[2] - r20 * pIn[3];
        pOut[3] = r01 * pIn[1] - r02 * pIn[2] + r00 * pIn[3];

        // direct code for quadratics is faster than ZYZ reccurence relations

        const float t41 = r01 * r00;
        const float t43 = r11 * r10;
        const float t48 = r11 * r12;
        const float t50 = r01 * r02;
        const float t55 = r02 * r02;
        const float t57 = r22 * r22;
        const float t58 = r12 * r12;
        const float t61 = r00 * r02;
        const float t63 = r10 * r12;
        const float t68 = r10 * r10;
        const float t70 = r01 * r01;
        const float t72 = r11 * r11;
        const float t74 = r00 * r00;
        const float t76 = r21 * r21;
        const float t78 = r20 * r20;

        const float v173 = 0.1732050808e1f;
        const float v577 = 0.5773502693e0f;
        const float v115 = 0.1154700539e1f;
        const float v288 = 0.2886751347e0f;
        const float v866 = 0.8660254040e0f;

        R[0] = r11 * r00 + r01 * r10;
        R[1] = -r01 * r12 - r11 * r02;
        R[2] = v173 * r02 * r12;
        R[3] = -r10 * r02 - r00 * r12;
        R[4] = r00 * r10 - r01 * r11;
        R[5] = -r11 * r20 - r21 * r10;
        R[6] = r11 * r22 + r21 * r12;
        R[7] = -v173 * r22 * r12;
        R[8] = r20 * r12 + r10 * r22;
        R[9] = -r10 * r20 + r11 * r21;
        R[10] = -v577 * (t41 + t43) + v115 * r21 * r20;
        R[11] = v577 * (t48 + t50) - v115 * r21 * r22;
        R[12] = -0.5000000000e0f * (t55 + t58) + t57;
        R[13] = v577 * (t61 + t63) - v115 * r20 * r22;
        R[14] = v288 * (t70 - t68 + t72 - t74) - v577 * (t76 - t78);
        R[15] = -r01 * r20 - r21 * r00;
        R[16] = r01 * r22 + r21 * r02;
        R[17] = -v173 * r22 * r02;
        R[18] = r00 * r22 + r20 * r02;
        R[19] = -r00 * r20 + r01 * r21;
        R[20] = t41 - t43;
        R[21] = -t50 + t48;
        R[22] = v866 * (t55 - t58);
        R[23] = t63 - t61;
        R[24] = 0.5000000000e0f * (t74 - t68 - t70 + t72);

        // blow the matrix multiply out by hand, looping is ineficient on a P4...
        for (unsigned int iR = 0; iR < 5; iR++)
        {
            const unsigned int uBase = iR * 5;
            pOut[4 + iR] = R[uBase + 0] * pIn[4] + R[uBase + 1] * pIn[5] + R[uBase + 2] * pIn[6] + R[uBase + 3] * pIn[7] + R[uBase + 4] * pIn[8];
        }
    }
    break;

    case 4:
        sh3_rot(mRot, const_cast<float*>(pIn), pOut);
        break;

    case 5:
        sh4_rot(mRot, const_cast<float*>(pIn), pOut);
        break;

    case 6:
        sh5_rot(mRot, const_cast<float*>(pIn), pOut);
        break;

    default:
        assert(Order < D3DXSH_MINORDER || Order > D3DXSH_MAXORDER);
        return nullptr;
    }

    return pOut;
}

float* STUB_API D3DXSHRotateZ(float* pOut, uint32_t Order, float Angle, const float* pIn)
{
    if (!pOut || !pIn)
        return nullptr;

    if (pOut == pIn)
        return nullptr;

    if (Order < D3DXSH_MINORDER || Order > D3DXSH_MAXORDER)
        return nullptr;

    float R[(2 * (D3DXSH_MAXORDER - 1) + 1) * (2 * (D3DXSH_MAXORDER - 1) + 1)]; // used to store rotation matrices...

    // these are actually very sparse matrices, most of the entries are zero's...

    const float ca = cosf(Angle);
    const float sa = sinf(Angle);

    const float t1 = ca;
    const float t2 = sa;
    R[0] = t1;
    R[1] = 0.0f;
    R[2] = t2;
    R[3] = 0.0f;
    R[4] = 1.0f;
    R[5] = 0.0f;
    R[6] = -t2;
    R[7] = 0.0f;
    R[8] = t1;

    pOut[0] = pIn[0];
    SimpMatMul(3, R, pIn + 1, pOut + 1);

    if (Order > 2)
    {
        for (int j = 0; j < 5 * 5; j++) R[j] = 0.0f;
        const float t1 = sa;
        const float t2 = t1 * t1;
        const float t3 = ca;
        const float t4 = t3 * t3;
        const float t5 = -t2 + t4;
        const float t7 = 2.0f * t3 * t1;
        R[0] = t5;
        R[4] = t7;
        R[6] = t3;
        R[8] = t1;
        R[12] = 1.0f;
        R[16] = -t1;
        R[18] = t3;
        R[20] = -t7;
        R[24] = t5;

        SimpMatMul(5, R, pIn + 4, pOut + 4); // un-roll matrix/vector multiply
        if (Order > 3)
        {
            for (int j = 0; j < 7 * 7; j++) R[j] = 0.0f;
            const float t1 = ca;
            const float t2 = t1 * t1;
            const float t4 = sa;
            const float t5 = t4 * t4;
            const float t8 = t2 * t1 - 3.0f * t1 * t5;
            const float t12 = 3.0f * t4 * t2 - t5 * t4;
            const float t13 = -t5 + t2;
            const float t15 = 2.0f * t1 * t4;
            R[0] = t8;
            R[6] = t12;
            R[8] = t13;
            R[12] = t15;
            R[16] = t1;
            R[18] = t4;
            R[24] = 1.0f;
            R[30] = -t4;
            R[32] = t1;
            R[36] = -t15;
            R[40] = t13;
            R[42] = -t12;
            R[48] = t8;
            SimpMatMul(7, R, pIn + 9, pOut + 9);
            if (Order > 4)
            {
                for (int j = 0; j <= 9 * 9; j++) R[j] = 0.0f;
                const float t1 = ca;
                const float t2 = t1 * t1;
                const float t3 = t2 * t2;
                const float t4 = sa;
                const float t5 = t4 * t4;
                const float t6 = t5 * t5;
                const float t9 = t3 + t6 - 6.0f * t5 * t2;
                const float t10 = t5 * t4;
                const float t12 = t2 * t1;
                const float t14 = -t10 * t1 + t4 * t12;
                const float t17 = t12 - 3.0f * t1 * t5;
                const float t20 = 3.0f * t4 * t2 - t10;
                const float t21 = -t5 + t2;
                const float t23 = 2.0f * t1 * t4;
                R[0] = t9;
                R[8] = 4.0f * t14;
                R[10] = t17;
                R[16] = t20;
                R[20] = t21;
                R[24] = t23;
                R[30] = t1;
                R[32] = t4;
                R[40] = 1.0f;
                R[48] = -t4;
                R[50] = t1;
                R[56] = -t23;
                R[60] = t21;
                R[64] = -t20;
                R[70] = t17;
                R[72] = -4.0f * t14;
                R[80] = t9;

                SimpMatMul(9, R, pIn + 16, pOut + 16);
                if (Order > 5)
                {
                    for (int j = 0; j < 11 * 11; j++) R[j] = 0.0f;
                    const float t1 = ca;
                    const float t2 = sa;
                    const float t3 = t2 * t2;
                    const float t4 = t3 * t3;
                    const float t7 = t1 * t1;
                    const float t8 = t7 * t1;
                    const float t11 = t7 * t7;
                    const float t13 = 5.0f * t1 * t4 - 10.0f * t3 * t8 + t11 * t1;
                    const float t14 = t3 * t2;
                    const float t20 = -10.0f * t14 * t7 + 5.0f * t2 * t11 + t4 * t2;
                    const float t23 = t11 + t4 - 6.0f * t3 * t7;
                    const float t26 = -t14 * t1 + t2 * t8;
                    const float t29 = t8 - 3.0f * t1 * t3;
                    const float t32 = 3.0f * t2 * t7 - t14;
                    const float t33 = -t3 + t7;
                    const float t35 = 2.0f * t1 * t2;
                    R[0] = t13;
                    R[10] = t20;
                    R[12] = t23;
                    R[20] = 4.0f * t26;
                    R[24] = t29;
                    R[30] = t32;
                    R[36] = t33;
                    R[40] = t35;
                    R[48] = t1;
                    R[50] = t2;
                    R[60] = 1.0f;
                    R[70] = -t2;
                    R[72] = t1;
                    R[80] = -t35;
                    R[84] = t33;
                    R[90] = -t32;
                    R[96] = t29;
                    R[100] = -4.0f * t26;
                    R[108] = t23;
                    R[110] = -t20;
                    R[120] = t13;
                    SimpMatMul(11, R, pIn + 25, pOut + 25);
                }
            }
        }
    }

    return pOut;
}

float* STUB_API D3DXSHAdd(float* pOut, uint32_t Order, const float* pA, const float* pB)
{
    if (!pOut || !pA || !pB)
        return nullptr;

    const size_t numcoeff = Order * Order;

    for (size_t i = 0; i < numcoeff; ++i)
    {
        pOut[i] = pA[i] + pB[i];
    }

    return pOut;
}

float* STUB_API D3DXSHScale(float* pOut, uint32_t Order, const float* pIn, const float Scale)
{
    if (!pOut || !pIn)
        return nullptr;

    const size_t numcoeff = Order * Order;

    for (size_t i = 0; i < numcoeff; ++i)
    {
        pOut[i] = Scale * pIn[i];
    }

    return pOut;
}

float STUB_API D3DXSHDot(uint32_t Order, const float* pA, const float* pB)
{
    if (!pA || !pB)
        return 0.f;

    float result = pA[0] * pB[0];

    const size_t numcoeff = Order * Order;

    for (size_t i = 1; i < numcoeff; ++i)
    {
        result += pA[i] * pB[i];
    }

    return result;
}

float* STUB_API D3DXSHMultiply2(float* y, const float* f, const float* g)
{
    if (!y || !f || !g)
        return nullptr;

    REAL tf, tg, t;
    // [0,0]: 0,
    y[0] = CONSTANT(0.282094792935999980) * f[0] * g[0];

    // [1,1]: 0,
    tf = CONSTANT(0.282094791773000010) * f[0];
    tg = CONSTANT(0.282094791773000010) * g[0];
    y[1] = tf * g[1] + tg * f[1];
    t = f[1] * g[1];
    y[0] += CONSTANT(0.282094791773000010) * t;

    // [2,2]: 0,
    tf = CONSTANT(0.282094795249000000) * f[0];
    tg = CONSTANT(0.282094795249000000) * g[0];
    y[2] = tf * g[2] + tg * f[2];
    t = f[2] * g[2];
    y[0] += CONSTANT(0.282094795249000000) * t;

    // [3,3]: 0,
    tf = CONSTANT(0.282094791773000010) * f[0];
    tg = CONSTANT(0.282094791773000010) * g[0];
    y[3] = tf * g[3] + tg * f[3];
    t = f[3] * g[3];
    y[0] += CONSTANT(0.282094791773000010) * t;

    // multiply count=20

    return y;
}

float* STUB_API D3DXSHMultiply3(float* y, const float* f, const float* g)
{
    if (!y || !f || !g)
        return nullptr;

    REAL tf, tg, t;
    // [0,0]: 0,
    y[0] = CONSTANT(0.282094792935999980) * f[0] * g[0];

    // [1,1]: 0,6,8,
    tf = CONSTANT(0.282094791773000010) * f[0] + CONSTANT(-0.126156626101000010) * f[6] + CONSTANT(-0.218509686119999990) * f[8];
    tg = CONSTANT(0.282094791773000010) * g[0] + CONSTANT(-0.126156626101000010) * g[6] + CONSTANT(-0.218509686119999990) * g[8];
    y[1] = tf * g[1] + tg * f[1];
    t = f[1] * g[1];
    y[0] += CONSTANT(0.282094791773000010) * t;
    y[6] = CONSTANT(-0.126156626101000010) * t;
    y[8] = CONSTANT(-0.218509686119999990) * t;

    // [1,2]: 5,
    tf = CONSTANT(0.218509686118000010) * f[5];
    tg = CONSTANT(0.218509686118000010) * g[5];
    y[1] += tf * g[2] + tg * f[2];
    y[2] = tf * g[1] + tg * f[1];
    t = f[1] * g[2] + f[2] * g[1];
    y[5] = CONSTANT(0.218509686118000010) * t;

    // [1,3]: 4,
    tf = CONSTANT(0.218509686114999990) * f[4];
    tg = CONSTANT(0.218509686114999990) * g[4];
    y[1] += tf * g[3] + tg * f[3];
    y[3] = tf * g[1] + tg * f[1];
    t = f[1] * g[3] + f[3] * g[1];
    y[4] = CONSTANT(0.218509686114999990) * t;

    // [2,2]: 0,6,
    tf = CONSTANT(0.282094795249000000) * f[0] + CONSTANT(0.252313259986999990) * f[6];
    tg = CONSTANT(0.282094795249000000) * g[0] + CONSTANT(0.252313259986999990) * g[6];
    y[2] += tf * g[2] + tg * f[2];
    t = f[2] * g[2];
    y[0] += CONSTANT(0.282094795249000000) * t;
    y[6] += CONSTANT(0.252313259986999990) * t;

    // [2,3]: 7,
    tf = CONSTANT(0.218509686118000010) * f[7];
    tg = CONSTANT(0.218509686118000010) * g[7];
    y[2] += tf * g[3] + tg * f[3];
    y[3] += tf * g[2] + tg * f[2];
    t = f[2] * g[3] + f[3] * g[2];
    y[7] = CONSTANT(0.218509686118000010) * t;

    // [3,3]: 0,6,8,
    tf = CONSTANT(0.282094791773000010) * f[0] + CONSTANT(-0.126156626101000010) * f[6] + CONSTANT(0.218509686119999990) * f[8];
    tg = CONSTANT(0.282094791773000010) * g[0] + CONSTANT(-0.126156626101000010) * g[6] + CONSTANT(0.218509686119999990) * g[8];
    y[3] += tf * g[3] + tg * f[3];
    t = f[3] * g[3];
    y[0] += CONSTANT(0.282094791773000010) * t;
    y[6] += CONSTANT(-0.126156626101000010) * t;
    y[8] += CONSTANT(0.218509686119999990) * t;

    // [4,4]: 0,6,
    tf = CONSTANT(0.282094791770000020) * f[0] + CONSTANT(-0.180223751576000010) * f[6];
    tg = CONSTANT(0.282094791770000020) * g[0] + CONSTANT(-0.180223751576000010) * g[6];
    y[4] += tf * g[4] + tg * f[4];
    t = f[4] * g[4];
    y[0] += CONSTANT(0.282094791770000020) * t;
    y[6] += CONSTANT(-0.180223751576000010) * t;

    // [4,5]: 7,
    tf = CONSTANT(0.156078347226000000) * f[7];
    tg = CONSTANT(0.156078347226000000) * g[7];
    y[4] += tf * g[5] + tg * f[5];
    y[5] += tf * g[4] + tg * f[4];
    t = f[4] * g[5] + f[5] * g[4];
    y[7] += CONSTANT(0.156078347226000000) * t;

    // [5,5]: 0,6,8,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.090111875786499998) * f[6] + CONSTANT(-0.156078347227999990) * f[8];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.090111875786499998) * g[6] + CONSTANT(-0.156078347227999990) * g[8];
    y[5] += tf * g[5] + tg * f[5];
    t = f[5] * g[5];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[6] += CONSTANT(0.090111875786499998) * t;
    y[8] += CONSTANT(-0.156078347227999990) * t;

    // [6,6]: 0,6,
    tf = CONSTANT(0.282094797560000000) * f[0];
    tg = CONSTANT(0.282094797560000000) * g[0];
    y[6] += tf * g[6] + tg * f[6];
    t = f[6] * g[6];
    y[0] += CONSTANT(0.282094797560000000) * t;
    y[6] += CONSTANT(0.180223764527000010) * t;

    // [7,7]: 0,6,8,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.090111875786499998) * f[6] + CONSTANT(0.156078347227999990) * f[8];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.090111875786499998) * g[6] + CONSTANT(0.156078347227999990) * g[8];
    y[7] += tf * g[7] + tg * f[7];
    t = f[7] * g[7];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[6] += CONSTANT(0.090111875786499998) * t;
    y[8] += CONSTANT(0.156078347227999990) * t;

    // [8,8]: 0,6,
    tf = CONSTANT(0.282094791770000020) * f[0] + CONSTANT(-0.180223751576000010) * f[6];
    tg = CONSTANT(0.282094791770000020) * g[0] + CONSTANT(-0.180223751576000010) * g[6];
    y[8] += tf * g[8] + tg * f[8];
    t = f[8] * g[8];
    y[0] += CONSTANT(0.282094791770000020) * t;
    y[6] += CONSTANT(-0.180223751576000010) * t;

    // multiply count=120

    return y;
}

float* STUB_API D3DXSHMultiply4(float* y, const float* f, const float* g)
{
    if (!y || !f || !g)
        return nullptr;

    REAL tf, tg, t;
    // [0,0]: 0,
    y[0] = CONSTANT(0.282094792935999980) * f[0] * g[0];

    // [1,1]: 0,6,8,
    tf = CONSTANT(0.282094791773000010) * f[0] + CONSTANT(-0.126156626101000010) * f[6] + CONSTANT(-0.218509686119999990) * f[8];
    tg = CONSTANT(0.282094791773000010) * g[0] + CONSTANT(-0.126156626101000010) * g[6] + CONSTANT(-0.218509686119999990) * g[8];
    y[1] = tf * g[1] + tg * f[1];
    t = f[1] * g[1];
    y[0] += CONSTANT(0.282094791773000010) * t;
    y[6] = CONSTANT(-0.126156626101000010) * t;
    y[8] = CONSTANT(-0.218509686119999990) * t;

    // [1,4]: 3,13,15,
    tf = CONSTANT(0.218509686114999990) * f[3] + CONSTANT(-0.058399170082300000) * f[13] + CONSTANT(-0.226179013157999990) * f[15];
    tg = CONSTANT(0.218509686114999990) * g[3] + CONSTANT(-0.058399170082300000) * g[13] + CONSTANT(-0.226179013157999990) * g[15];
    y[1] += tf * g[4] + tg * f[4];
    y[4] = tf * g[1] + tg * f[1];
    t = f[1] * g[4] + f[4] * g[1];
    y[3] = CONSTANT(0.218509686114999990) * t;
    y[13] = CONSTANT(-0.058399170082300000) * t;
    y[15] = CONSTANT(-0.226179013157999990) * t;

    // [1,5]: 2,12,14,
    tf = CONSTANT(0.218509686118000010) * f[2] + CONSTANT(-0.143048168103000000) * f[12] + CONSTANT(-0.184674390923000000) * f[14];
    tg = CONSTANT(0.218509686118000010) * g[2] + CONSTANT(-0.143048168103000000) * g[12] + CONSTANT(-0.184674390923000000) * g[14];
    y[1] += tf * g[5] + tg * f[5];
    y[5] = tf * g[1] + tg * f[1];
    t = f[1] * g[5] + f[5] * g[1];
    y[2] = CONSTANT(0.218509686118000010) * t;
    y[12] = CONSTANT(-0.143048168103000000) * t;
    y[14] = CONSTANT(-0.184674390923000000) * t;

    // [1,6]: 11,
    tf = CONSTANT(0.202300659402999990) * f[11];
    tg = CONSTANT(0.202300659402999990) * g[11];
    y[1] += tf * g[6] + tg * f[6];
    y[6] += tf * g[1] + tg * f[1];
    t = f[1] * g[6] + f[6] * g[1];
    y[11] = CONSTANT(0.202300659402999990) * t;

    // [1,8]: 9,11,
    tf = CONSTANT(0.226179013155000000) * f[9] + CONSTANT(0.058399170081799998) * f[11];
    tg = CONSTANT(0.226179013155000000) * g[9] + CONSTANT(0.058399170081799998) * g[11];
    y[1] += tf * g[8] + tg * f[8];
    y[8] += tf * g[1] + tg * f[1];
    t = f[1] * g[8] + f[8] * g[1];
    y[9] = CONSTANT(0.226179013155000000) * t;
    y[11] += CONSTANT(0.058399170081799998) * t;

    // [2,2]: 0,6,
    tf = CONSTANT(0.282094795249000000) * f[0] + CONSTANT(0.252313259986999990) * f[6];
    tg = CONSTANT(0.282094795249000000) * g[0] + CONSTANT(0.252313259986999990) * g[6];
    y[2] += tf * g[2] + tg * f[2];
    t = f[2] * g[2];
    y[0] += CONSTANT(0.282094795249000000) * t;
    y[6] += CONSTANT(0.252313259986999990) * t;

    // [2,6]: 12,
    tf = CONSTANT(0.247766706973999990) * f[12];
    tg = CONSTANT(0.247766706973999990) * g[12];
    y[2] += tf * g[6] + tg * f[6];
    y[6] += tf * g[2] + tg * f[2];
    t = f[2] * g[6] + f[6] * g[2];
    y[12] += CONSTANT(0.247766706973999990) * t;

    // [3,3]: 0,6,8,
    tf = CONSTANT(0.282094791773000010) * f[0] + CONSTANT(-0.126156626101000010) * f[6] + CONSTANT(0.218509686119999990) * f[8];
    tg = CONSTANT(0.282094791773000010) * g[0] + CONSTANT(-0.126156626101000010) * g[6] + CONSTANT(0.218509686119999990) * g[8];
    y[3] += tf * g[3] + tg * f[3];
    t = f[3] * g[3];
    y[0] += CONSTANT(0.282094791773000010) * t;
    y[6] += CONSTANT(-0.126156626101000010) * t;
    y[8] += CONSTANT(0.218509686119999990) * t;

    // [3,6]: 13,
    tf = CONSTANT(0.202300659402999990) * f[13];
    tg = CONSTANT(0.202300659402999990) * g[13];
    y[3] += tf * g[6] + tg * f[6];
    y[6] += tf * g[3] + tg * f[3];
    t = f[3] * g[6] + f[6] * g[3];
    y[13] += CONSTANT(0.202300659402999990) * t;

    // [3,7]: 2,12,14,
    tf = CONSTANT(0.218509686118000010) * f[2] + CONSTANT(-0.143048168103000000) * f[12] + CONSTANT(0.184674390923000000) * f[14];
    tg = CONSTANT(0.218509686118000010) * g[2] + CONSTANT(-0.143048168103000000) * g[12] + CONSTANT(0.184674390923000000) * g[14];
    y[3] += tf * g[7] + tg * f[7];
    y[7] = tf * g[3] + tg * f[3];
    t = f[3] * g[7] + f[7] * g[3];
    y[2] += CONSTANT(0.218509686118000010) * t;
    y[12] += CONSTANT(-0.143048168103000000) * t;
    y[14] += CONSTANT(0.184674390923000000) * t;

    // [3,8]: 13,15,
    tf = CONSTANT(-0.058399170081799998) * f[13] + CONSTANT(0.226179013155000000) * f[15];
    tg = CONSTANT(-0.058399170081799998) * g[13] + CONSTANT(0.226179013155000000) * g[15];
    y[3] += tf * g[8] + tg * f[8];
    y[8] += tf * g[3] + tg * f[3];
    t = f[3] * g[8] + f[8] * g[3];
    y[13] += CONSTANT(-0.058399170081799998) * t;
    y[15] += CONSTANT(0.226179013155000000) * t;

    // [4,4]: 0,6,
    tf = CONSTANT(0.282094791770000020) * f[0] + CONSTANT(-0.180223751576000010) * f[6];
    tg = CONSTANT(0.282094791770000020) * g[0] + CONSTANT(-0.180223751576000010) * g[6];
    y[4] += tf * g[4] + tg * f[4];
    t = f[4] * g[4];
    y[0] += CONSTANT(0.282094791770000020) * t;
    y[6] += CONSTANT(-0.180223751576000010) * t;

    // [4,5]: 7,
    tf = CONSTANT(0.156078347226000000) * f[7];
    tg = CONSTANT(0.156078347226000000) * g[7];
    y[4] += tf * g[5] + tg * f[5];
    y[5] += tf * g[4] + tg * f[4];
    t = f[4] * g[5] + f[5] * g[4];
    y[7] += CONSTANT(0.156078347226000000) * t;

    // [4,9]: 3,13,
    tf = CONSTANT(0.226179013157999990) * f[3] + CONSTANT(-0.094031597258400004) * f[13];
    tg = CONSTANT(0.226179013157999990) * g[3] + CONSTANT(-0.094031597258400004) * g[13];
    y[4] += tf * g[9] + tg * f[9];
    y[9] += tf * g[4] + tg * f[4];
    t = f[4] * g[9] + f[9] * g[4];
    y[3] += CONSTANT(0.226179013157999990) * t;
    y[13] += CONSTANT(-0.094031597258400004) * t;

    // [4,10]: 2,12,
    tf = CONSTANT(0.184674390919999990) * f[2] + CONSTANT(-0.188063194517999990) * f[12];
    tg = CONSTANT(0.184674390919999990) * g[2] + CONSTANT(-0.188063194517999990) * g[12];
    y[4] += tf * g[10] + tg * f[10];
    y[10] = tf * g[4] + tg * f[4];
    t = f[4] * g[10] + f[10] * g[4];
    y[2] += CONSTANT(0.184674390919999990) * t;
    y[12] += CONSTANT(-0.188063194517999990) * t;

    // [4,11]: 3,13,15,
    tf = CONSTANT(-0.058399170082300000) * f[3] + CONSTANT(0.145673124078000010) * f[13] + CONSTANT(0.094031597258400004) * f[15];
    tg = CONSTANT(-0.058399170082300000) * g[3] + CONSTANT(0.145673124078000010) * g[13] + CONSTANT(0.094031597258400004) * g[15];
    y[4] += tf * g[11] + tg * f[11];
    y[11] += tf * g[4] + tg * f[4];
    t = f[4] * g[11] + f[11] * g[4];
    y[3] += CONSTANT(-0.058399170082300000) * t;
    y[13] += CONSTANT(0.145673124078000010) * t;
    y[15] += CONSTANT(0.094031597258400004) * t;

    // [5,5]: 0,6,8,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.090111875786499998) * f[6] + CONSTANT(-0.156078347227999990) * f[8];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.090111875786499998) * g[6] + CONSTANT(-0.156078347227999990) * g[8];
    y[5] += tf * g[5] + tg * f[5];
    t = f[5] * g[5];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[6] += CONSTANT(0.090111875786499998) * t;
    y[8] += CONSTANT(-0.156078347227999990) * t;

    // [5,9]: 14,
    tf = CONSTANT(0.148677009677999990) * f[14];
    tg = CONSTANT(0.148677009677999990) * g[14];
    y[5] += tf * g[9] + tg * f[9];
    y[9] += tf * g[5] + tg * f[5];
    t = f[5] * g[9] + f[9] * g[5];
    y[14] += CONSTANT(0.148677009677999990) * t;

    // [5,10]: 3,13,15,
    tf = CONSTANT(0.184674390919999990) * f[3] + CONSTANT(0.115164716490000000) * f[13] + CONSTANT(-0.148677009678999990) * f[15];
    tg = CONSTANT(0.184674390919999990) * g[3] + CONSTANT(0.115164716490000000) * g[13] + CONSTANT(-0.148677009678999990) * g[15];
    y[5] += tf * g[10] + tg * f[10];
    y[10] += tf * g[5] + tg * f[5];
    t = f[5] * g[10] + f[10] * g[5];
    y[3] += CONSTANT(0.184674390919999990) * t;
    y[13] += CONSTANT(0.115164716490000000) * t;
    y[15] += CONSTANT(-0.148677009678999990) * t;

    // [5,11]: 2,12,14,
    tf = CONSTANT(0.233596680327000010) * f[2] + CONSTANT(0.059470803871800003) * f[12] + CONSTANT(-0.115164716491000000) * f[14];
    tg = CONSTANT(0.233596680327000010) * g[2] + CONSTANT(0.059470803871800003) * g[12] + CONSTANT(-0.115164716491000000) * g[14];
    y[5] += tf * g[11] + tg * f[11];
    y[11] += tf * g[5] + tg * f[5];
    t = f[5] * g[11] + f[11] * g[5];
    y[2] += CONSTANT(0.233596680327000010) * t;
    y[12] += CONSTANT(0.059470803871800003) * t;
    y[14] += CONSTANT(-0.115164716491000000) * t;

    // [6,6]: 0,6,
    tf = CONSTANT(0.282094797560000000) * f[0];
    tg = CONSTANT(0.282094797560000000) * g[0];
    y[6] += tf * g[6] + tg * f[6];
    t = f[6] * g[6];
    y[0] += CONSTANT(0.282094797560000000) * t;
    y[6] += CONSTANT(0.180223764527000010) * t;

    // [7,7]: 6,0,8,
    tf = CONSTANT(0.090111875786499998) * f[6] + CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.156078347227999990) * f[8];
    tg = CONSTANT(0.090111875786499998) * g[6] + CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.156078347227999990) * g[8];
    y[7] += tf * g[7] + tg * f[7];
    t = f[7] * g[7];
    y[6] += CONSTANT(0.090111875786499998) * t;
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[8] += CONSTANT(0.156078347227999990) * t;

    // [7,10]: 9,1,11,
    tf = CONSTANT(0.148677009678999990) * f[9] + CONSTANT(0.184674390919999990) * f[1] + CONSTANT(0.115164716490000000) * f[11];
    tg = CONSTANT(0.148677009678999990) * g[9] + CONSTANT(0.184674390919999990) * g[1] + CONSTANT(0.115164716490000000) * g[11];
    y[7] += tf * g[10] + tg * f[10];
    y[10] += tf * g[7] + tg * f[7];
    t = f[7] * g[10] + f[10] * g[7];
    y[9] += CONSTANT(0.148677009678999990) * t;
    y[1] += CONSTANT(0.184674390919999990) * t;
    y[11] += CONSTANT(0.115164716490000000) * t;

    // [7,13]: 12,2,14,
    tf = CONSTANT(0.059470803871800003) * f[12] + CONSTANT(0.233596680327000010) * f[2] + CONSTANT(0.115164716491000000) * f[14];
    tg = CONSTANT(0.059470803871800003) * g[12] + CONSTANT(0.233596680327000010) * g[2] + CONSTANT(0.115164716491000000) * g[14];
    y[7] += tf * g[13] + tg * f[13];
    y[13] += tf * g[7] + tg * f[7];
    t = f[7] * g[13] + f[13] * g[7];
    y[12] += CONSTANT(0.059470803871800003) * t;
    y[2] += CONSTANT(0.233596680327000010) * t;
    y[14] += CONSTANT(0.115164716491000000) * t;

    // [7,14]: 15,
    tf = CONSTANT(0.148677009677999990) * f[15];
    tg = CONSTANT(0.148677009677999990) * g[15];
    y[7] += tf * g[14] + tg * f[14];
    y[14] += tf * g[7] + tg * f[7];
    t = f[7] * g[14] + f[14] * g[7];
    y[15] += CONSTANT(0.148677009677999990) * t;

    // [8,8]: 0,6,
    tf = CONSTANT(0.282094791770000020) * f[0] + CONSTANT(-0.180223751576000010) * f[6];
    tg = CONSTANT(0.282094791770000020) * g[0] + CONSTANT(-0.180223751576000010) * g[6];
    y[8] += tf * g[8] + tg * f[8];
    t = f[8] * g[8];
    y[0] += CONSTANT(0.282094791770000020) * t;
    y[6] += CONSTANT(-0.180223751576000010) * t;

    // [8,9]: 11,
    tf = CONSTANT(-0.094031597259499999) * f[11];
    tg = CONSTANT(-0.094031597259499999) * g[11];
    y[8] += tf * g[9] + tg * f[9];
    y[9] += tf * g[8] + tg * f[8];
    t = f[8] * g[9] + f[9] * g[8];
    y[11] += CONSTANT(-0.094031597259499999) * t;

    // [8,13]: 15,
    tf = CONSTANT(-0.094031597259499999) * f[15];
    tg = CONSTANT(-0.094031597259499999) * g[15];
    y[8] += tf * g[13] + tg * f[13];
    y[13] += tf * g[8] + tg * f[8];
    t = f[8] * g[13] + f[13] * g[8];
    y[15] += CONSTANT(-0.094031597259499999) * t;

    // [8,14]: 2,12,
    tf = CONSTANT(0.184674390919999990) * f[2] + CONSTANT(-0.188063194517999990) * f[12];
    tg = CONSTANT(0.184674390919999990) * g[2] + CONSTANT(-0.188063194517999990) * g[12];
    y[8] += tf * g[14] + tg * f[14];
    y[14] += tf * g[8] + tg * f[8];
    t = f[8] * g[14] + f[14] * g[8];
    y[2] += CONSTANT(0.184674390919999990) * t;
    y[12] += CONSTANT(-0.188063194517999990) * t;

    // [9,9]: 6,0,
    tf = CONSTANT(-0.210261043508000010) * f[6] + CONSTANT(0.282094791766999970) * f[0];
    tg = CONSTANT(-0.210261043508000010) * g[6] + CONSTANT(0.282094791766999970) * g[0];
    y[9] += tf * g[9] + tg * f[9];
    t = f[9] * g[9];
    y[6] += CONSTANT(-0.210261043508000010) * t;
    y[0] += CONSTANT(0.282094791766999970) * t;

    // [10,10]: 0,
    tf = CONSTANT(0.282094791771999980) * f[0];
    tg = CONSTANT(0.282094791771999980) * g[0];
    y[10] += tf * g[10] + tg * f[10];
    t = f[10] * g[10];
    y[0] += CONSTANT(0.282094791771999980) * t;

    // [11,11]: 0,6,8,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.126156626101000010) * f[6] + CONSTANT(-0.145673124078999990) * f[8];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.126156626101000010) * g[6] + CONSTANT(-0.145673124078999990) * g[8];
    y[11] += tf * g[11] + tg * f[11];
    t = f[11] * g[11];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[6] += CONSTANT(0.126156626101000010) * t;
    y[8] += CONSTANT(-0.145673124078999990) * t;

    // [12,12]: 0,6,
    tf = CONSTANT(0.282094799871999980) * f[0] + CONSTANT(0.168208852954000010) * f[6];
    tg = CONSTANT(0.282094799871999980) * g[0] + CONSTANT(0.168208852954000010) * g[6];
    y[12] += tf * g[12] + tg * f[12];
    t = f[12] * g[12];
    y[0] += CONSTANT(0.282094799871999980) * t;
    y[6] += CONSTANT(0.168208852954000010) * t;

    // [13,13]: 0,8,6,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.145673124078999990) * f[8] + CONSTANT(0.126156626101000010) * f[6];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.145673124078999990) * g[8] + CONSTANT(0.126156626101000010) * g[6];
    y[13] += tf * g[13] + tg * f[13];
    t = f[13] * g[13];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[8] += CONSTANT(0.145673124078999990) * t;
    y[6] += CONSTANT(0.126156626101000010) * t;

    // [14,14]: 0,
    tf = CONSTANT(0.282094791771999980) * f[0];
    tg = CONSTANT(0.282094791771999980) * g[0];
    y[14] += tf * g[14] + tg * f[14];
    t = f[14] * g[14];
    y[0] += CONSTANT(0.282094791771999980) * t;

    // [15,15]: 0,6,
    tf = CONSTANT(0.282094791766999970) * f[0] + CONSTANT(-0.210261043508000010) * f[6];
    tg = CONSTANT(0.282094791766999970) * g[0] + CONSTANT(-0.210261043508000010) * g[6];
    y[15] += tf * g[15] + tg * f[15];
    t = f[15] * g[15];
    y[0] += CONSTANT(0.282094791766999970) * t;
    y[6] += CONSTANT(-0.210261043508000010) * t;

    // multiply count=399

    return y;
}

float* STUB_API D3DXSHMultiply5(float* y, const float* f, const float* g)
{
    if (!y || !f || !g)
        return nullptr;

    REAL tf, tg, t;
    // [0,0]: 0,
    y[0] = CONSTANT(0.282094792935999980) * f[0] * g[0];

    // [1,1]: 0,6,8,
    tf = CONSTANT(0.282094791773000010) * f[0] + CONSTANT(-0.126156626101000010) * f[6] + CONSTANT(-0.218509686119999990) * f[8];
    tg = CONSTANT(0.282094791773000010) * g[0] + CONSTANT(-0.126156626101000010) * g[6] + CONSTANT(-0.218509686119999990) * g[8];
    y[1] = tf * g[1] + tg * f[1];
    t = f[1] * g[1];
    y[0] += CONSTANT(0.282094791773000010) * t;
    y[6] = CONSTANT(-0.126156626101000010) * t;
    y[8] = CONSTANT(-0.218509686119999990) * t;

    // [1,4]: 3,13,15,
    tf = CONSTANT(0.218509686114999990) * f[3] + CONSTANT(-0.058399170082300000) * f[13] + CONSTANT(-0.226179013157999990) * f[15];
    tg = CONSTANT(0.218509686114999990) * g[3] + CONSTANT(-0.058399170082300000) * g[13] + CONSTANT(-0.226179013157999990) * g[15];
    y[1] += tf * g[4] + tg * f[4];
    y[4] = tf * g[1] + tg * f[1];
    t = f[1] * g[4] + f[4] * g[1];
    y[3] = CONSTANT(0.218509686114999990) * t;
    y[13] = CONSTANT(-0.058399170082300000) * t;
    y[15] = CONSTANT(-0.226179013157999990) * t;

    // [1,5]: 2,12,14,
    tf = CONSTANT(0.218509686118000010) * f[2] + CONSTANT(-0.143048168103000000) * f[12] + CONSTANT(-0.184674390923000000) * f[14];
    tg = CONSTANT(0.218509686118000010) * g[2] + CONSTANT(-0.143048168103000000) * g[12] + CONSTANT(-0.184674390923000000) * g[14];
    y[1] += tf * g[5] + tg * f[5];
    y[5] = tf * g[1] + tg * f[1];
    t = f[1] * g[5] + f[5] * g[1];
    y[2] = CONSTANT(0.218509686118000010) * t;
    y[12] = CONSTANT(-0.143048168103000000) * t;
    y[14] = CONSTANT(-0.184674390923000000) * t;

    // [1,9]: 8,22,24,
    tf = CONSTANT(0.226179013155000000) * f[8] + CONSTANT(-0.043528171378199997) * f[22] + CONSTANT(-0.230329432978999990) * f[24];
    tg = CONSTANT(0.226179013155000000) * g[8] + CONSTANT(-0.043528171378199997) * g[22] + CONSTANT(-0.230329432978999990) * g[24];
    y[1] += tf * g[9] + tg * f[9];
    y[9] = tf * g[1] + tg * f[1];
    t = f[1] * g[9] + f[9] * g[1];
    y[8] += CONSTANT(0.226179013155000000) * t;
    y[22] = CONSTANT(-0.043528171378199997) * t;
    y[24] = CONSTANT(-0.230329432978999990) * t;

    // [1,10]: 7,21,23,
    tf = CONSTANT(0.184674390919999990) * f[7] + CONSTANT(-0.075393004386799994) * f[21] + CONSTANT(-0.199471140200000010) * f[23];
    tg = CONSTANT(0.184674390919999990) * g[7] + CONSTANT(-0.075393004386799994) * g[21] + CONSTANT(-0.199471140200000010) * g[23];
    y[1] += tf * g[10] + tg * f[10];
    y[10] = tf * g[1] + tg * f[1];
    t = f[1] * g[10] + f[10] * g[1];
    y[7] = CONSTANT(0.184674390919999990) * t;
    y[21] = CONSTANT(-0.075393004386799994) * t;
    y[23] = CONSTANT(-0.199471140200000010) * t;

    // [1,11]: 6,8,20,22,
    tf = CONSTANT(0.202300659402999990) * f[6] + CONSTANT(0.058399170081799998) * f[8] + CONSTANT(-0.150786008773000000) * f[20] + CONSTANT(-0.168583882836999990) * f[22];
    tg = CONSTANT(0.202300659402999990) * g[6] + CONSTANT(0.058399170081799998) * g[8] + CONSTANT(-0.150786008773000000) * g[20] + CONSTANT(-0.168583882836999990) * g[22];
    y[1] += tf * g[11] + tg * f[11];
    y[11] = tf * g[1] + tg * f[1];
    t = f[1] * g[11] + f[11] * g[1];
    y[6] += CONSTANT(0.202300659402999990) * t;
    y[8] += CONSTANT(0.058399170081799998) * t;
    y[20] = CONSTANT(-0.150786008773000000) * t;
    y[22] += CONSTANT(-0.168583882836999990) * t;

    // [1,12]: 19,
    tf = CONSTANT(0.194663900273000010) * f[19];
    tg = CONSTANT(0.194663900273000010) * g[19];
    y[1] += tf * g[12] + tg * f[12];
    y[12] += tf * g[1] + tg * f[1];
    t = f[1] * g[12] + f[12] * g[1];
    y[19] = CONSTANT(0.194663900273000010) * t;

    // [1,13]: 18,
    tf = CONSTANT(0.168583882834000000) * f[18];
    tg = CONSTANT(0.168583882834000000) * g[18];
    y[1] += tf * g[13] + tg * f[13];
    y[13] += tf * g[1] + tg * f[1];
    t = f[1] * g[13] + f[13] * g[1];
    y[18] = CONSTANT(0.168583882834000000) * t;

    // [1,14]: 17,19,
    tf = CONSTANT(0.199471140196999990) * f[17] + CONSTANT(0.075393004386399995) * f[19];
    tg = CONSTANT(0.199471140196999990) * g[17] + CONSTANT(0.075393004386399995) * g[19];
    y[1] += tf * g[14] + tg * f[14];
    y[14] += tf * g[1] + tg * f[1];
    t = f[1] * g[14] + f[14] * g[1];
    y[17] = CONSTANT(0.199471140196999990) * t;
    y[19] += CONSTANT(0.075393004386399995) * t;

    // [1,15]: 16,18,
    tf = CONSTANT(0.230329432973999990) * f[16] + CONSTANT(0.043528171377799997) * f[18];
    tg = CONSTANT(0.230329432973999990) * g[16] + CONSTANT(0.043528171377799997) * g[18];
    y[1] += tf * g[15] + tg * f[15];
    y[15] += tf * g[1] + tg * f[1];
    t = f[1] * g[15] + f[15] * g[1];
    y[16] = CONSTANT(0.230329432973999990) * t;
    y[18] += CONSTANT(0.043528171377799997) * t;

    // [2,2]: 0,6,
    tf = CONSTANT(0.282094795249000000) * f[0] + CONSTANT(0.252313259986999990) * f[6];
    tg = CONSTANT(0.282094795249000000) * g[0] + CONSTANT(0.252313259986999990) * g[6];
    y[2] += tf * g[2] + tg * f[2];
    t = f[2] * g[2];
    y[0] += CONSTANT(0.282094795249000000) * t;
    y[6] += CONSTANT(0.252313259986999990) * t;

    // [2,10]: 4,18,
    tf = CONSTANT(0.184674390919999990) * f[4] + CONSTANT(0.213243618621000000) * f[18];
    tg = CONSTANT(0.184674390919999990) * g[4] + CONSTANT(0.213243618621000000) * g[18];
    y[2] += tf * g[10] + tg * f[10];
    y[10] += tf * g[2] + tg * f[2];
    t = f[2] * g[10] + f[10] * g[2];
    y[4] += CONSTANT(0.184674390919999990) * t;
    y[18] += CONSTANT(0.213243618621000000) * t;

    // [2,12]: 6,20,
    tf = CONSTANT(0.247766706973999990) * f[6] + CONSTANT(0.246232537174000010) * f[20];
    tg = CONSTANT(0.247766706973999990) * g[6] + CONSTANT(0.246232537174000010) * g[20];
    y[2] += tf * g[12] + tg * f[12];
    y[12] += tf * g[2] + tg * f[2];
    t = f[2] * g[12] + f[12] * g[2];
    y[6] += CONSTANT(0.247766706973999990) * t;
    y[20] += CONSTANT(0.246232537174000010) * t;

    // [2,14]: 8,22,
    tf = CONSTANT(0.184674390919999990) * f[8] + CONSTANT(0.213243618621000000) * f[22];
    tg = CONSTANT(0.184674390919999990) * g[8] + CONSTANT(0.213243618621000000) * g[22];
    y[2] += tf * g[14] + tg * f[14];
    y[14] += tf * g[2] + tg * f[2];
    t = f[2] * g[14] + f[14] * g[2];
    y[8] += CONSTANT(0.184674390919999990) * t;
    y[22] += CONSTANT(0.213243618621000000) * t;

    // [3,3]: 0,6,8,
    tf = CONSTANT(0.282094791773000010) * f[0] + CONSTANT(-0.126156626101000010) * f[6] + CONSTANT(0.218509686119999990) * f[8];
    tg = CONSTANT(0.282094791773000010) * g[0] + CONSTANT(-0.126156626101000010) * g[6] + CONSTANT(0.218509686119999990) * g[8];
    y[3] += tf * g[3] + tg * f[3];
    t = f[3] * g[3];
    y[0] += CONSTANT(0.282094791773000010) * t;
    y[6] += CONSTANT(-0.126156626101000010) * t;
    y[8] += CONSTANT(0.218509686119999990) * t;

    // [3,7]: 2,12,14,
    tf = CONSTANT(0.218509686118000010) * f[2] + CONSTANT(-0.143048168103000000) * f[12] + CONSTANT(0.184674390923000000) * f[14];
    tg = CONSTANT(0.218509686118000010) * g[2] + CONSTANT(-0.143048168103000000) * g[12] + CONSTANT(0.184674390923000000) * g[14];
    y[3] += tf * g[7] + tg * f[7];
    y[7] += tf * g[3] + tg * f[3];
    t = f[3] * g[7] + f[7] * g[3];
    y[2] += CONSTANT(0.218509686118000010) * t;
    y[12] += CONSTANT(-0.143048168103000000) * t;
    y[14] += CONSTANT(0.184674390923000000) * t;

    // [3,9]: 4,16,18,
    tf = CONSTANT(0.226179013157999990) * f[4] + CONSTANT(0.230329432973999990) * f[16] + CONSTANT(-0.043528171377799997) * f[18];
    tg = CONSTANT(0.226179013157999990) * g[4] + CONSTANT(0.230329432973999990) * g[16] + CONSTANT(-0.043528171377799997) * g[18];
    y[3] += tf * g[9] + tg * f[9];
    y[9] += tf * g[3] + tg * f[3];
    t = f[3] * g[9] + f[9] * g[3];
    y[4] += CONSTANT(0.226179013157999990) * t;
    y[16] += CONSTANT(0.230329432973999990) * t;
    y[18] += CONSTANT(-0.043528171377799997) * t;

    // [3,10]: 5,17,19,
    tf = CONSTANT(0.184674390919999990) * f[5] + CONSTANT(0.199471140200000010) * f[17] + CONSTANT(-0.075393004386799994) * f[19];
    tg = CONSTANT(0.184674390919999990) * g[5] + CONSTANT(0.199471140200000010) * g[17] + CONSTANT(-0.075393004386799994) * g[19];
    y[3] += tf * g[10] + tg * f[10];
    y[10] += tf * g[3] + tg * f[3];
    t = f[3] * g[10] + f[10] * g[3];
    y[5] += CONSTANT(0.184674390919999990) * t;
    y[17] += CONSTANT(0.199471140200000010) * t;
    y[19] += CONSTANT(-0.075393004386799994) * t;

    // [3,12]: 21,
    tf = CONSTANT(0.194663900273000010) * f[21];
    tg = CONSTANT(0.194663900273000010) * g[21];
    y[3] += tf * g[12] + tg * f[12];
    y[12] += tf * g[3] + tg * f[3];
    t = f[3] * g[12] + f[12] * g[3];
    y[21] += CONSTANT(0.194663900273000010) * t;

    // [3,13]: 8,6,20,22,
    tf = CONSTANT(-0.058399170081799998) * f[8] + CONSTANT(0.202300659402999990) * f[6] + CONSTANT(-0.150786008773000000) * f[20] + CONSTANT(0.168583882836999990) * f[22];
    tg = CONSTANT(-0.058399170081799998) * g[8] + CONSTANT(0.202300659402999990) * g[6] + CONSTANT(-0.150786008773000000) * g[20] + CONSTANT(0.168583882836999990) * g[22];
    y[3] += tf * g[13] + tg * f[13];
    y[13] += tf * g[3] + tg * f[3];
    t = f[3] * g[13] + f[13] * g[3];
    y[8] += CONSTANT(-0.058399170081799998) * t;
    y[6] += CONSTANT(0.202300659402999990) * t;
    y[20] += CONSTANT(-0.150786008773000000) * t;
    y[22] += CONSTANT(0.168583882836999990) * t;

    // [3,14]: 21,23,
    tf = CONSTANT(-0.075393004386399995) * f[21] + CONSTANT(0.199471140196999990) * f[23];
    tg = CONSTANT(-0.075393004386399995) * g[21] + CONSTANT(0.199471140196999990) * g[23];
    y[3] += tf * g[14] + tg * f[14];
    y[14] += tf * g[3] + tg * f[3];
    t = f[3] * g[14] + f[14] * g[3];
    y[21] += CONSTANT(-0.075393004386399995) * t;
    y[23] += CONSTANT(0.199471140196999990) * t;

    // [3,15]: 8,22,24,
    tf = CONSTANT(0.226179013155000000) * f[8] + CONSTANT(-0.043528171378199997) * f[22] + CONSTANT(0.230329432978999990) * f[24];
    tg = CONSTANT(0.226179013155000000) * g[8] + CONSTANT(-0.043528171378199997) * g[22] + CONSTANT(0.230329432978999990) * g[24];
    y[3] += tf * g[15] + tg * f[15];
    y[15] += tf * g[3] + tg * f[3];
    t = f[3] * g[15] + f[15] * g[3];
    y[8] += CONSTANT(0.226179013155000000) * t;
    y[22] += CONSTANT(-0.043528171378199997) * t;
    y[24] += CONSTANT(0.230329432978999990) * t;

    // [4,4]: 0,6,20,24,
    tf = CONSTANT(0.282094791770000020) * f[0] + CONSTANT(-0.180223751576000010) * f[6] + CONSTANT(0.040299255967500003) * f[20] + CONSTANT(-0.238413613505999990) * f[24];
    tg = CONSTANT(0.282094791770000020) * g[0] + CONSTANT(-0.180223751576000010) * g[6] + CONSTANT(0.040299255967500003) * g[20] + CONSTANT(-0.238413613505999990) * g[24];
    y[4] += tf * g[4] + tg * f[4];
    t = f[4] * g[4];
    y[0] += CONSTANT(0.282094791770000020) * t;
    y[6] += CONSTANT(-0.180223751576000010) * t;
    y[20] += CONSTANT(0.040299255967500003) * t;
    y[24] += CONSTANT(-0.238413613505999990) * t;

    // [4,5]: 7,21,23,
    tf = CONSTANT(0.156078347226000000) * f[7] + CONSTANT(-0.063718718434399996) * f[21] + CONSTANT(-0.168583882835000000) * f[23];
    tg = CONSTANT(0.156078347226000000) * g[7] + CONSTANT(-0.063718718434399996) * g[21] + CONSTANT(-0.168583882835000000) * g[23];
    y[4] += tf * g[5] + tg * f[5];
    y[5] += tf * g[4] + tg * f[4];
    t = f[4] * g[5] + f[5] * g[4];
    y[7] += CONSTANT(0.156078347226000000) * t;
    y[21] += CONSTANT(-0.063718718434399996) * t;
    y[23] += CONSTANT(-0.168583882835000000) * t;

    // [4,11]: 3,13,15,
    tf = CONSTANT(-0.058399170082300000) * f[3] + CONSTANT(0.145673124078000010) * f[13] + CONSTANT(0.094031597258400004) * f[15];
    tg = CONSTANT(-0.058399170082300000) * g[3] + CONSTANT(0.145673124078000010) * g[13] + CONSTANT(0.094031597258400004) * g[15];
    y[4] += tf * g[11] + tg * f[11];
    y[11] += tf * g[4] + tg * f[4];
    t = f[4] * g[11] + f[11] * g[4];
    y[3] += CONSTANT(-0.058399170082300000) * t;
    y[13] += CONSTANT(0.145673124078000010) * t;
    y[15] += CONSTANT(0.094031597258400004) * t;

    // [4,16]: 8,22,
    tf = CONSTANT(0.238413613494000000) * f[8] + CONSTANT(-0.075080816693699995) * f[22];
    tg = CONSTANT(0.238413613494000000) * g[8] + CONSTANT(-0.075080816693699995) * g[22];
    y[4] += tf * g[16] + tg * f[16];
    y[16] += tf * g[4] + tg * f[4];
    t = f[4] * g[16] + f[16] * g[4];
    y[8] += CONSTANT(0.238413613494000000) * t;
    y[22] += CONSTANT(-0.075080816693699995) * t;

    // [4,18]: 6,20,24,
    tf = CONSTANT(0.156078347226000000) * f[6] + CONSTANT(-0.190364615029000010) * f[20] + CONSTANT(0.075080816691500005) * f[24];
    tg = CONSTANT(0.156078347226000000) * g[6] + CONSTANT(-0.190364615029000010) * g[20] + CONSTANT(0.075080816691500005) * g[24];
    y[4] += tf * g[18] + tg * f[18];
    y[18] += tf * g[4] + tg * f[4];
    t = f[4] * g[18] + f[18] * g[4];
    y[6] += CONSTANT(0.156078347226000000) * t;
    y[20] += CONSTANT(-0.190364615029000010) * t;
    y[24] += CONSTANT(0.075080816691500005) * t;

    // [4,19]: 7,21,23,
    tf = CONSTANT(-0.063718718434399996) * f[7] + CONSTANT(0.141889406569999990) * f[21] + CONSTANT(0.112621225039000000) * f[23];
    tg = CONSTANT(-0.063718718434399996) * g[7] + CONSTANT(0.141889406569999990) * g[21] + CONSTANT(0.112621225039000000) * g[23];
    y[4] += tf * g[19] + tg * f[19];
    y[19] += tf * g[4] + tg * f[4];
    t = f[4] * g[19] + f[19] * g[4];
    y[7] += CONSTANT(-0.063718718434399996) * t;
    y[21] += CONSTANT(0.141889406569999990) * t;
    y[23] += CONSTANT(0.112621225039000000) * t;

    // [5,5]: 0,6,8,20,22,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.090111875786499998) * f[6] + CONSTANT(-0.156078347227999990) * f[8] + CONSTANT(-0.161197023870999990) * f[20] + CONSTANT(-0.180223751574000000) * f[22];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.090111875786499998) * g[6] + CONSTANT(-0.156078347227999990) * g[8] + CONSTANT(-0.161197023870999990) * g[20] + CONSTANT(-0.180223751574000000) * g[22];
    y[5] += tf * g[5] + tg * f[5];
    t = f[5] * g[5];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[6] += CONSTANT(0.090111875786499998) * t;
    y[8] += CONSTANT(-0.156078347227999990) * t;
    y[20] += CONSTANT(-0.161197023870999990) * t;
    y[22] += CONSTANT(-0.180223751574000000) * t;

    // [5,11]: 2,12,14,
    tf = CONSTANT(0.233596680327000010) * f[2] + CONSTANT(0.059470803871800003) * f[12] + CONSTANT(-0.115164716491000000) * f[14];
    tg = CONSTANT(0.233596680327000010) * g[2] + CONSTANT(0.059470803871800003) * g[12] + CONSTANT(-0.115164716491000000) * g[14];
    y[5] += tf * g[11] + tg * f[11];
    y[11] += tf * g[5] + tg * f[5];
    t = f[5] * g[11] + f[11] * g[5];
    y[2] += CONSTANT(0.233596680327000010) * t;
    y[12] += CONSTANT(0.059470803871800003) * t;
    y[14] += CONSTANT(-0.115164716491000000) * t;

    // [5,17]: 8,22,24,
    tf = CONSTANT(0.168583882832999990) * f[8] + CONSTANT(0.132725386548000010) * f[22] + CONSTANT(-0.140463346189000000) * f[24];
    tg = CONSTANT(0.168583882832999990) * g[8] + CONSTANT(0.132725386548000010) * g[22] + CONSTANT(-0.140463346189000000) * g[24];
    y[5] += tf * g[17] + tg * f[17];
    y[17] += tf * g[5] + tg * f[5];
    t = f[5] * g[17] + f[17] * g[5];
    y[8] += CONSTANT(0.168583882832999990) * t;
    y[22] += CONSTANT(0.132725386548000010) * t;
    y[24] += CONSTANT(-0.140463346189000000) * t;

    // [5,18]: 7,21,23,
    tf = CONSTANT(0.180223751571000010) * f[7] + CONSTANT(0.090297865407399994) * f[21] + CONSTANT(-0.132725386549000010) * f[23];
    tg = CONSTANT(0.180223751571000010) * g[7] + CONSTANT(0.090297865407399994) * g[21] + CONSTANT(-0.132725386549000010) * g[23];
    y[5] += tf * g[18] + tg * f[18];
    y[18] += tf * g[5] + tg * f[5];
    t = f[5] * g[18] + f[18] * g[5];
    y[7] += CONSTANT(0.180223751571000010) * t;
    y[21] += CONSTANT(0.090297865407399994) * t;
    y[23] += CONSTANT(-0.132725386549000010) * t;

    // [5,19]: 6,8,20,22,
    tf = CONSTANT(0.220728115440999990) * f[6] + CONSTANT(0.063718718433900007) * f[8] + CONSTANT(0.044869370061299998) * f[20] + CONSTANT(-0.090297865408399999) * f[22];
    tg = CONSTANT(0.220728115440999990) * g[6] + CONSTANT(0.063718718433900007) * g[8] + CONSTANT(0.044869370061299998) * g[20] + CONSTANT(-0.090297865408399999) * g[22];
    y[5] += tf * g[19] + tg * f[19];
    y[19] += tf * g[5] + tg * f[5];
    t = f[5] * g[19] + f[19] * g[5];
    y[6] += CONSTANT(0.220728115440999990) * t;
    y[8] += CONSTANT(0.063718718433900007) * t;
    y[20] += CONSTANT(0.044869370061299998) * t;
    y[22] += CONSTANT(-0.090297865408399999) * t;

    // [6,6]: 0,6,20,
    tf = CONSTANT(0.282094797560000000) * f[0] + CONSTANT(0.241795553185999990) * f[20];
    tg = CONSTANT(0.282094797560000000) * g[0] + CONSTANT(0.241795553185999990) * g[20];
    y[6] += tf * g[6] + tg * f[6];
    t = f[6] * g[6];
    y[0] += CONSTANT(0.282094797560000000) * t;
    y[6] += CONSTANT(0.180223764527000010) * t;
    y[20] += CONSTANT(0.241795553185999990) * t;

    // [7,7]: 6,0,8,20,22,
    tf = CONSTANT(0.090111875786499998) * f[6] + CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.156078347227999990) * f[8] + CONSTANT(-0.161197023870999990) * f[20] + CONSTANT(0.180223751574000000) * f[22];
    tg = CONSTANT(0.090111875786499998) * g[6] + CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.156078347227999990) * g[8] + CONSTANT(-0.161197023870999990) * g[20] + CONSTANT(0.180223751574000000) * g[22];
    y[7] += tf * g[7] + tg * f[7];
    t = f[7] * g[7];
    y[6] += CONSTANT(0.090111875786499998) * t;
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[8] += CONSTANT(0.156078347227999990) * t;
    y[20] += CONSTANT(-0.161197023870999990) * t;
    y[22] += CONSTANT(0.180223751574000000) * t;

    // [7,13]: 12,2,14,
    tf = CONSTANT(0.059470803871800003) * f[12] + CONSTANT(0.233596680327000010) * f[2] + CONSTANT(0.115164716491000000) * f[14];
    tg = CONSTANT(0.059470803871800003) * g[12] + CONSTANT(0.233596680327000010) * g[2] + CONSTANT(0.115164716491000000) * g[14];
    y[7] += tf * g[13] + tg * f[13];
    y[13] += tf * g[7] + tg * f[7];
    t = f[7] * g[13] + f[13] * g[7];
    y[12] += CONSTANT(0.059470803871800003) * t;
    y[2] += CONSTANT(0.233596680327000010) * t;
    y[14] += CONSTANT(0.115164716491000000) * t;

    // [7,17]: 16,4,18,
    tf = CONSTANT(0.140463346187999990) * f[16] + CONSTANT(0.168583882835000000) * f[4] + CONSTANT(0.132725386549000010) * f[18];
    tg = CONSTANT(0.140463346187999990) * g[16] + CONSTANT(0.168583882835000000) * g[4] + CONSTANT(0.132725386549000010) * g[18];
    y[7] += tf * g[17] + tg * f[17];
    y[17] += tf * g[7] + tg * f[7];
    t = f[7] * g[17] + f[17] * g[7];
    y[16] += CONSTANT(0.140463346187999990) * t;
    y[4] += CONSTANT(0.168583882835000000) * t;
    y[18] += CONSTANT(0.132725386549000010) * t;

    // [7,21]: 8,20,6,22,
    tf = CONSTANT(-0.063718718433900007) * f[8] + CONSTANT(0.044869370061299998) * f[20] + CONSTANT(0.220728115440999990) * f[6] + CONSTANT(0.090297865408399999) * f[22];
    tg = CONSTANT(-0.063718718433900007) * g[8] + CONSTANT(0.044869370061299998) * g[20] + CONSTANT(0.220728115440999990) * g[6] + CONSTANT(0.090297865408399999) * g[22];
    y[7] += tf * g[21] + tg * f[21];
    y[21] += tf * g[7] + tg * f[7];
    t = f[7] * g[21] + f[21] * g[7];
    y[8] += CONSTANT(-0.063718718433900007) * t;
    y[20] += CONSTANT(0.044869370061299998) * t;
    y[6] += CONSTANT(0.220728115440999990) * t;
    y[22] += CONSTANT(0.090297865408399999) * t;

    // [7,23]: 8,22,24,
    tf = CONSTANT(0.168583882832999990) * f[8] + CONSTANT(0.132725386548000010) * f[22] + CONSTANT(0.140463346189000000) * f[24];
    tg = CONSTANT(0.168583882832999990) * g[8] + CONSTANT(0.132725386548000010) * g[22] + CONSTANT(0.140463346189000000) * g[24];
    y[7] += tf * g[23] + tg * f[23];
    y[23] += tf * g[7] + tg * f[7];
    t = f[7] * g[23] + f[23] * g[7];
    y[8] += CONSTANT(0.168583882832999990) * t;
    y[22] += CONSTANT(0.132725386548000010) * t;
    y[24] += CONSTANT(0.140463346189000000) * t;

    // [8,8]: 0,6,20,24,
    tf = CONSTANT(0.282094791770000020) * f[0] + CONSTANT(-0.180223751576000010) * f[6] + CONSTANT(0.040299255967500003) * f[20] + CONSTANT(0.238413613505999990) * f[24];
    tg = CONSTANT(0.282094791770000020) * g[0] + CONSTANT(-0.180223751576000010) * g[6] + CONSTANT(0.040299255967500003) * g[20] + CONSTANT(0.238413613505999990) * g[24];
    y[8] += tf * g[8] + tg * f[8];
    t = f[8] * g[8];
    y[0] += CONSTANT(0.282094791770000020) * t;
    y[6] += CONSTANT(-0.180223751576000010) * t;
    y[20] += CONSTANT(0.040299255967500003) * t;
    y[24] += CONSTANT(0.238413613505999990) * t;

    // [8,22]: 6,20,24,
    tf = CONSTANT(0.156078347226000000) * f[6] + CONSTANT(-0.190364615029000010) * f[20] + CONSTANT(-0.075080816691500005) * f[24];
    tg = CONSTANT(0.156078347226000000) * g[6] + CONSTANT(-0.190364615029000010) * g[20] + CONSTANT(-0.075080816691500005) * g[24];
    y[8] += tf * g[22] + tg * f[22];
    y[22] += tf * g[8] + tg * f[8];
    t = f[8] * g[22] + f[22] * g[8];
    y[6] += CONSTANT(0.156078347226000000) * t;
    y[20] += CONSTANT(-0.190364615029000010) * t;
    y[24] += CONSTANT(-0.075080816691500005) * t;

    // [9,9]: 6,0,20,
    tf = CONSTANT(-0.210261043508000010) * f[6] + CONSTANT(0.282094791766999970) * f[0] + CONSTANT(0.076934943209800002) * f[20];
    tg = CONSTANT(-0.210261043508000010) * g[6] + CONSTANT(0.282094791766999970) * g[0] + CONSTANT(0.076934943209800002) * g[20];
    y[9] += tf * g[9] + tg * f[9];
    t = f[9] * g[9];
    y[6] += CONSTANT(-0.210261043508000010) * t;
    y[0] += CONSTANT(0.282094791766999970) * t;
    y[20] += CONSTANT(0.076934943209800002) * t;

    // [9,10]: 7,21,
    tf = CONSTANT(0.148677009678999990) * f[7] + CONSTANT(-0.099322584599600000) * f[21];
    tg = CONSTANT(0.148677009678999990) * g[7] + CONSTANT(-0.099322584599600000) * g[21];
    y[9] += tf * g[10] + tg * f[10];
    y[10] += tf * g[9] + tg * f[9];
    t = f[9] * g[10] + f[10] * g[9];
    y[7] += CONSTANT(0.148677009678999990) * t;
    y[21] += CONSTANT(-0.099322584599600000) * t;

    // [9,11]: 8,22,24,
    tf = CONSTANT(-0.094031597259499999) * f[8] + CONSTANT(0.133255230518000010) * f[22] + CONSTANT(0.117520066950999990) * f[24];
    tg = CONSTANT(-0.094031597259499999) * g[8] + CONSTANT(0.133255230518000010) * g[22] + CONSTANT(0.117520066950999990) * g[24];
    y[9] += tf * g[11] + tg * f[11];
    y[11] += tf * g[9] + tg * f[9];
    t = f[9] * g[11] + f[11] * g[9];
    y[8] += CONSTANT(-0.094031597259499999) * t;
    y[22] += CONSTANT(0.133255230518000010) * t;
    y[24] += CONSTANT(0.117520066950999990) * t;

    // [9,13]: 4,16,18,
    tf = CONSTANT(-0.094031597258400004) * f[4] + CONSTANT(-0.117520066953000000) * f[16] + CONSTANT(0.133255230519000010) * f[18];
    tg = CONSTANT(-0.094031597258400004) * g[4] + CONSTANT(-0.117520066953000000) * g[16] + CONSTANT(0.133255230519000010) * g[18];
    y[9] += tf * g[13] + tg * f[13];
    y[13] += tf * g[9] + tg * f[9];
    t = f[9] * g[13] + f[13] * g[9];
    y[4] += CONSTANT(-0.094031597258400004) * t;
    y[16] += CONSTANT(-0.117520066953000000) * t;
    y[18] += CONSTANT(0.133255230519000010) * t;

    // [9,14]: 5,19,
    tf = CONSTANT(0.148677009677999990) * f[5] + CONSTANT(-0.099322584600699995) * f[19];
    tg = CONSTANT(0.148677009677999990) * g[5] + CONSTANT(-0.099322584600699995) * g[19];
    y[9] += tf * g[14] + tg * f[14];
    y[14] += tf * g[9] + tg * f[9];
    t = f[9] * g[14] + f[14] * g[9];
    y[5] += CONSTANT(0.148677009677999990) * t;
    y[19] += CONSTANT(-0.099322584600699995) * t;

    // [9,17]: 2,12,
    tf = CONSTANT(0.162867503964999990) * f[2] + CONSTANT(-0.203550726872999990) * f[12];
    tg = CONSTANT(0.162867503964999990) * g[2] + CONSTANT(-0.203550726872999990) * g[12];
    y[9] += tf * g[17] + tg * f[17];
    y[17] += tf * g[9] + tg * f[9];
    t = f[9] * g[17] + f[17] * g[9];
    y[2] += CONSTANT(0.162867503964999990) * t;
    y[12] += CONSTANT(-0.203550726872999990) * t;

    // [10,10]: 0,20,24,
    tf = CONSTANT(0.282094791771999980) * f[0] + CONSTANT(-0.179514867494000000) * f[20] + CONSTANT(-0.151717754049000010) * f[24];
    tg = CONSTANT(0.282094791771999980) * g[0] + CONSTANT(-0.179514867494000000) * g[20] + CONSTANT(-0.151717754049000010) * g[24];
    y[10] += tf * g[10] + tg * f[10];
    t = f[10] * g[10];
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[20] += CONSTANT(-0.179514867494000000) * t;
    y[24] += CONSTANT(-0.151717754049000010) * t;

    // [10,11]: 7,21,23,
    tf = CONSTANT(0.115164716490000000) * f[7] + CONSTANT(0.102579924281000000) * f[21] + CONSTANT(-0.067850242288900006) * f[23];
    tg = CONSTANT(0.115164716490000000) * g[7] + CONSTANT(0.102579924281000000) * g[21] + CONSTANT(-0.067850242288900006) * g[23];
    y[10] += tf * g[11] + tg * f[11];
    y[11] += tf * g[10] + tg * f[10];
    t = f[10] * g[11] + f[11] * g[10];
    y[7] += CONSTANT(0.115164716490000000) * t;
    y[21] += CONSTANT(0.102579924281000000) * t;
    y[23] += CONSTANT(-0.067850242288900006) * t;

    // [10,12]: 4,18,
    tf = CONSTANT(-0.188063194517999990) * f[4] + CONSTANT(-0.044418410173299998) * f[18];
    tg = CONSTANT(-0.188063194517999990) * g[4] + CONSTANT(-0.044418410173299998) * g[18];
    y[10] += tf * g[12] + tg * f[12];
    y[12] += tf * g[10] + tg * f[10];
    t = f[10] * g[12] + f[12] * g[10];
    y[4] += CONSTANT(-0.188063194517999990) * t;
    y[18] += CONSTANT(-0.044418410173299998) * t;

    // [10,13]: 5,17,19,
    tf = CONSTANT(0.115164716490000000) * f[5] + CONSTANT(0.067850242288900006) * f[17] + CONSTANT(0.102579924281000000) * f[19];
    tg = CONSTANT(0.115164716490000000) * g[5] + CONSTANT(0.067850242288900006) * g[17] + CONSTANT(0.102579924281000000) * g[19];
    y[10] += tf * g[13] + tg * f[13];
    y[13] += tf * g[10] + tg * f[10];
    t = f[10] * g[13] + f[13] * g[10];
    y[5] += CONSTANT(0.115164716490000000) * t;
    y[17] += CONSTANT(0.067850242288900006) * t;
    y[19] += CONSTANT(0.102579924281000000) * t;

    // [10,14]: 16,
    tf = CONSTANT(0.151717754044999990) * f[16];
    tg = CONSTANT(0.151717754044999990) * g[16];
    y[10] += tf * g[14] + tg * f[14];
    y[14] += tf * g[10] + tg * f[10];
    t = f[10] * g[14] + f[14] * g[10];
    y[16] += CONSTANT(0.151717754044999990) * t;

    // [10,15]: 5,19,
    tf = CONSTANT(-0.148677009678999990) * f[5] + CONSTANT(0.099322584599600000) * f[19];
    tg = CONSTANT(-0.148677009678999990) * g[5] + CONSTANT(0.099322584599600000) * g[19];
    y[10] += tf * g[15] + tg * f[15];
    y[15] += tf * g[10] + tg * f[10];
    t = f[10] * g[15] + f[15] * g[10];
    y[5] += CONSTANT(-0.148677009678999990) * t;
    y[19] += CONSTANT(0.099322584599600000) * t;

    // [11,11]: 0,6,8,20,22,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.126156626101000010) * f[6] + CONSTANT(-0.145673124078999990) * f[8] + CONSTANT(0.025644981070299999) * f[20] + CONSTANT(-0.114687841910000000) * f[22];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.126156626101000010) * g[6] + CONSTANT(-0.145673124078999990) * g[8] + CONSTANT(0.025644981070299999) * g[20] + CONSTANT(-0.114687841910000000) * g[22];
    y[11] += tf * g[11] + tg * f[11];
    t = f[11] * g[11];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[6] += CONSTANT(0.126156626101000010) * t;
    y[8] += CONSTANT(-0.145673124078999990) * t;
    y[20] += CONSTANT(0.025644981070299999) * t;
    y[22] += CONSTANT(-0.114687841910000000) * t;

    // [11,14]: 17,
    tf = CONSTANT(0.067850242288500007) * f[17];
    tg = CONSTANT(0.067850242288500007) * g[17];
    y[11] += tf * g[14] + tg * f[14];
    y[14] += tf * g[11] + tg * f[11];
    t = f[11] * g[14] + f[14] * g[11];
    y[17] += CONSTANT(0.067850242288500007) * t;

    // [11,15]: 16,
    tf = CONSTANT(-0.117520066953000000) * f[16];
    tg = CONSTANT(-0.117520066953000000) * g[16];
    y[11] += tf * g[15] + tg * f[15];
    y[15] += tf * g[11] + tg * f[11];
    t = f[11] * g[15] + f[15] * g[11];
    y[16] += CONSTANT(-0.117520066953000000) * t;

    // [11,18]: 3,13,15,
    tf = CONSTANT(0.168583882834000000) * f[3] + CONSTANT(0.114687841909000000) * f[13] + CONSTANT(-0.133255230519000010) * f[15];
    tg = CONSTANT(0.168583882834000000) * g[3] + CONSTANT(0.114687841909000000) * g[13] + CONSTANT(-0.133255230519000010) * g[15];
    y[11] += tf * g[18] + tg * f[18];
    y[18] += tf * g[11] + tg * f[11];
    t = f[11] * g[18] + f[18] * g[11];
    y[3] += CONSTANT(0.168583882834000000) * t;
    y[13] += CONSTANT(0.114687841909000000) * t;
    y[15] += CONSTANT(-0.133255230519000010) * t;

    // [11,19]: 2,14,12,
    tf = CONSTANT(0.238413613504000000) * f[2] + CONSTANT(-0.102579924282000000) * f[14] + CONSTANT(0.099322584599300004) * f[12];
    tg = CONSTANT(0.238413613504000000) * g[2] + CONSTANT(-0.102579924282000000) * g[14] + CONSTANT(0.099322584599300004) * g[12];
    y[11] += tf * g[19] + tg * f[19];
    y[19] += tf * g[11] + tg * f[11];
    t = f[11] * g[19] + f[19] * g[11];
    y[2] += CONSTANT(0.238413613504000000) * t;
    y[14] += CONSTANT(-0.102579924282000000) * t;
    y[12] += CONSTANT(0.099322584599300004) * t;

    // [12,12]: 0,6,20,
    tf = CONSTANT(0.282094799871999980) * f[0] + CONSTANT(0.168208852954000010) * f[6] + CONSTANT(0.153869910786000010) * f[20];
    tg = CONSTANT(0.282094799871999980) * g[0] + CONSTANT(0.168208852954000010) * g[6] + CONSTANT(0.153869910786000010) * g[20];
    y[12] += tf * g[12] + tg * f[12];
    t = f[12] * g[12];
    y[0] += CONSTANT(0.282094799871999980) * t;
    y[6] += CONSTANT(0.168208852954000010) * t;
    y[20] += CONSTANT(0.153869910786000010) * t;

    // [12,14]: 8,22,
    tf = CONSTANT(-0.188063194517999990) * f[8] + CONSTANT(-0.044418410173299998) * f[22];
    tg = CONSTANT(-0.188063194517999990) * g[8] + CONSTANT(-0.044418410173299998) * g[22];
    y[12] += tf * g[14] + tg * f[14];
    y[14] += tf * g[12] + tg * f[12];
    t = f[12] * g[14] + f[14] * g[12];
    y[8] += CONSTANT(-0.188063194517999990) * t;
    y[22] += CONSTANT(-0.044418410173299998) * t;

    // [13,13]: 0,8,6,20,22,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.145673124078999990) * f[8] + CONSTANT(0.126156626101000010) * f[6] + CONSTANT(0.025644981070299999) * f[20] + CONSTANT(0.114687841910000000) * f[22];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.145673124078999990) * g[8] + CONSTANT(0.126156626101000010) * g[6] + CONSTANT(0.025644981070299999) * g[20] + CONSTANT(0.114687841910000000) * g[22];
    y[13] += tf * g[13] + tg * f[13];
    t = f[13] * g[13];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[8] += CONSTANT(0.145673124078999990) * t;
    y[6] += CONSTANT(0.126156626101000010) * t;
    y[20] += CONSTANT(0.025644981070299999) * t;
    y[22] += CONSTANT(0.114687841910000000) * t;

    // [13,14]: 23,
    tf = CONSTANT(0.067850242288500007) * f[23];
    tg = CONSTANT(0.067850242288500007) * g[23];
    y[13] += tf * g[14] + tg * f[14];
    y[14] += tf * g[13] + tg * f[13];
    t = f[13] * g[14] + f[14] * g[13];
    y[23] += CONSTANT(0.067850242288500007) * t;

    // [13,15]: 8,22,24,
    tf = CONSTANT(-0.094031597259499999) * f[8] + CONSTANT(0.133255230518000010) * f[22] + CONSTANT(-0.117520066950999990) * f[24];
    tg = CONSTANT(-0.094031597259499999) * g[8] + CONSTANT(0.133255230518000010) * g[22] + CONSTANT(-0.117520066950999990) * g[24];
    y[13] += tf * g[15] + tg * f[15];
    y[15] += tf * g[13] + tg * f[13];
    t = f[13] * g[15] + f[15] * g[13];
    y[8] += CONSTANT(-0.094031597259499999) * t;
    y[22] += CONSTANT(0.133255230518000010) * t;
    y[24] += CONSTANT(-0.117520066950999990) * t;

    // [13,21]: 2,12,14,
    tf = CONSTANT(0.238413613504000000) * f[2] + CONSTANT(0.099322584599300004) * f[12] + CONSTANT(0.102579924282000000) * f[14];
    tg = CONSTANT(0.238413613504000000) * g[2] + CONSTANT(0.099322584599300004) * g[12] + CONSTANT(0.102579924282000000) * g[14];
    y[13] += tf * g[21] + tg * f[21];
    y[21] += tf * g[13] + tg * f[13];
    t = f[13] * g[21] + f[21] * g[13];
    y[2] += CONSTANT(0.238413613504000000) * t;
    y[12] += CONSTANT(0.099322584599300004) * t;
    y[14] += CONSTANT(0.102579924282000000) * t;

    // [14,14]: 0,20,24,
    tf = CONSTANT(0.282094791771999980) * f[0] + CONSTANT(-0.179514867494000000) * f[20] + CONSTANT(0.151717754049000010) * f[24];
    tg = CONSTANT(0.282094791771999980) * g[0] + CONSTANT(-0.179514867494000000) * g[20] + CONSTANT(0.151717754049000010) * g[24];
    y[14] += tf * g[14] + tg * f[14];
    t = f[14] * g[14];
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[20] += CONSTANT(-0.179514867494000000) * t;
    y[24] += CONSTANT(0.151717754049000010) * t;

    // [14,15]: 7,21,
    tf = CONSTANT(0.148677009677999990) * f[7] + CONSTANT(-0.099322584600699995) * f[21];
    tg = CONSTANT(0.148677009677999990) * g[7] + CONSTANT(-0.099322584600699995) * g[21];
    y[14] += tf * g[15] + tg * f[15];
    y[15] += tf * g[14] + tg * f[14];
    t = f[14] * g[15] + f[15] * g[14];
    y[7] += CONSTANT(0.148677009677999990) * t;
    y[21] += CONSTANT(-0.099322584600699995) * t;

    // [15,15]: 0,6,20,
    tf = CONSTANT(0.282094791766999970) * f[0] + CONSTANT(-0.210261043508000010) * f[6] + CONSTANT(0.076934943209800002) * f[20];
    tg = CONSTANT(0.282094791766999970) * g[0] + CONSTANT(-0.210261043508000010) * g[6] + CONSTANT(0.076934943209800002) * g[20];
    y[15] += tf * g[15] + tg * f[15];
    t = f[15] * g[15];
    y[0] += CONSTANT(0.282094791766999970) * t;
    y[6] += CONSTANT(-0.210261043508000010) * t;
    y[20] += CONSTANT(0.076934943209800002) * t;

    // [15,23]: 12,2,
    tf = CONSTANT(-0.203550726872999990) * f[12] + CONSTANT(0.162867503964999990) * f[2];
    tg = CONSTANT(-0.203550726872999990) * g[12] + CONSTANT(0.162867503964999990) * g[2];
    y[15] += tf * g[23] + tg * f[23];
    y[23] += tf * g[15] + tg * f[15];
    t = f[15] * g[23] + f[23] * g[15];
    y[12] += CONSTANT(-0.203550726872999990) * t;
    y[2] += CONSTANT(0.162867503964999990) * t;

    // [16,16]: 0,6,20,
    tf = CONSTANT(0.282094791763999990) * f[0] + CONSTANT(-0.229375683829000000) * f[6] + CONSTANT(0.106525305981000000) * f[20];
    tg = CONSTANT(0.282094791763999990) * g[0] + CONSTANT(-0.229375683829000000) * g[6] + CONSTANT(0.106525305981000000) * g[20];
    y[16] += tf * g[16] + tg * f[16];
    t = f[16] * g[16];
    y[0] += CONSTANT(0.282094791763999990) * t;
    y[6] += CONSTANT(-0.229375683829000000) * t;
    y[20] += CONSTANT(0.106525305981000000) * t;

    // [16,18]: 8,22,
    tf = CONSTANT(-0.075080816693699995) * f[8] + CONSTANT(0.135045473380000000) * f[22];
    tg = CONSTANT(-0.075080816693699995) * g[8] + CONSTANT(0.135045473380000000) * g[22];
    y[16] += tf * g[18] + tg * f[18];
    y[18] += tf * g[16] + tg * f[16];
    t = f[16] * g[18] + f[18] * g[16];
    y[8] += CONSTANT(-0.075080816693699995) * t;
    y[22] += CONSTANT(0.135045473380000000) * t;

    // [16,23]: 19,5,
    tf = CONSTANT(-0.119098912754999990) * f[19] + CONSTANT(0.140463346187999990) * f[5];
    tg = CONSTANT(-0.119098912754999990) * g[19] + CONSTANT(0.140463346187999990) * g[5];
    y[16] += tf * g[23] + tg * f[23];
    y[23] += tf * g[16] + tg * f[16];
    t = f[16] * g[23] + f[23] * g[16];
    y[19] += CONSTANT(-0.119098912754999990) * t;
    y[5] += CONSTANT(0.140463346187999990) * t;

    // [17,17]: 0,6,20,
    tf = CONSTANT(0.282094791768999990) * f[0] + CONSTANT(-0.057343920955899998) * f[6] + CONSTANT(-0.159787958979000000) * f[20];
    tg = CONSTANT(0.282094791768999990) * g[0] + CONSTANT(-0.057343920955899998) * g[6] + CONSTANT(-0.159787958979000000) * g[20];
    y[17] += tf * g[17] + tg * f[17];
    t = f[17] * g[17];
    y[0] += CONSTANT(0.282094791768999990) * t;
    y[6] += CONSTANT(-0.057343920955899998) * t;
    y[20] += CONSTANT(-0.159787958979000000) * t;

    // [17,19]: 8,22,24,
    tf = CONSTANT(-0.112621225039000000) * f[8] + CONSTANT(0.045015157794100001) * f[22] + CONSTANT(0.119098912753000000) * f[24];
    tg = CONSTANT(-0.112621225039000000) * g[8] + CONSTANT(0.045015157794100001) * g[22] + CONSTANT(0.119098912753000000) * g[24];
    y[17] += tf * g[19] + tg * f[19];
    y[19] += tf * g[17] + tg * f[17];
    t = f[17] * g[19] + f[19] * g[17];
    y[8] += CONSTANT(-0.112621225039000000) * t;
    y[22] += CONSTANT(0.045015157794100001) * t;
    y[24] += CONSTANT(0.119098912753000000) * t;

    // [17,21]: 16,4,18,
    tf = CONSTANT(-0.119098912754999990) * f[16] + CONSTANT(-0.112621225039000000) * f[4] + CONSTANT(0.045015157794399997) * f[18];
    tg = CONSTANT(-0.119098912754999990) * g[16] + CONSTANT(-0.112621225039000000) * g[4] + CONSTANT(0.045015157794399997) * g[18];
    y[17] += tf * g[21] + tg * f[21];
    y[21] += tf * g[17] + tg * f[17];
    t = f[17] * g[21] + f[21] * g[17];
    y[16] += CONSTANT(-0.119098912754999990) * t;
    y[4] += CONSTANT(-0.112621225039000000) * t;
    y[18] += CONSTANT(0.045015157794399997) * t;

    // [18,18]: 6,0,20,24,
    tf = CONSTANT(0.065535909662600006) * f[6] + CONSTANT(0.282094791771999980) * f[0] + CONSTANT(-0.083698454702400005) * f[20] + CONSTANT(-0.135045473384000000) * f[24];
    tg = CONSTANT(0.065535909662600006) * g[6] + CONSTANT(0.282094791771999980) * g[0] + CONSTANT(-0.083698454702400005) * g[20] + CONSTANT(-0.135045473384000000) * g[24];
    y[18] += tf * g[18] + tg * f[18];
    t = f[18] * g[18];
    y[6] += CONSTANT(0.065535909662600006) * t;
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[20] += CONSTANT(-0.083698454702400005) * t;
    y[24] += CONSTANT(-0.135045473384000000) * t;

    // [18,19]: 7,21,23,
    tf = CONSTANT(0.090297865407399994) * f[7] + CONSTANT(0.102084782359000000) * f[21] + CONSTANT(-0.045015157794399997) * f[23];
    tg = CONSTANT(0.090297865407399994) * g[7] + CONSTANT(0.102084782359000000) * g[21] + CONSTANT(-0.045015157794399997) * g[23];
    y[18] += tf * g[19] + tg * f[19];
    y[19] += tf * g[18] + tg * f[18];
    t = f[18] * g[19] + f[19] * g[18];
    y[7] += CONSTANT(0.090297865407399994) * t;
    y[21] += CONSTANT(0.102084782359000000) * t;
    y[23] += CONSTANT(-0.045015157794399997) * t;

    // [19,19]: 6,8,0,20,22,
    tf = CONSTANT(0.139263808033999990) * f[6] + CONSTANT(-0.141889406570999990) * f[8] + CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.068480553847200004) * f[20] + CONSTANT(-0.102084782360000000) * f[22];
    tg = CONSTANT(0.139263808033999990) * g[6] + CONSTANT(-0.141889406570999990) * g[8] + CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.068480553847200004) * g[20] + CONSTANT(-0.102084782360000000) * g[22];
    y[19] += tf * g[19] + tg * f[19];
    t = f[19] * g[19];
    y[6] += CONSTANT(0.139263808033999990) * t;
    y[8] += CONSTANT(-0.141889406570999990) * t;
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[20] += CONSTANT(0.068480553847200004) * t;
    y[22] += CONSTANT(-0.102084782360000000) * t;

    // [20,20]: 6,0,20,
    tf = CONSTANT(0.163839797503000010) * f[6] + CONSTANT(0.282094802232000010) * f[0];
    tg = CONSTANT(0.163839797503000010) * g[6] + CONSTANT(0.282094802232000010) * g[0];
    y[20] += tf * g[20] + tg * f[20];
    t = f[20] * g[20];
    y[6] += CONSTANT(0.163839797503000010) * t;
    y[0] += CONSTANT(0.282094802232000010) * t;
    y[20] += CONSTANT(0.136961139005999990) * t;

    // [21,21]: 6,20,0,8,22,
    tf = CONSTANT(0.139263808033999990) * f[6] + CONSTANT(0.068480553847200004) * f[20] + CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.141889406570999990) * f[8] + CONSTANT(0.102084782360000000) * f[22];
    tg = CONSTANT(0.139263808033999990) * g[6] + CONSTANT(0.068480553847200004) * g[20] + CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.141889406570999990) * g[8] + CONSTANT(0.102084782360000000) * g[22];
    y[21] += tf * g[21] + tg * f[21];
    t = f[21] * g[21];
    y[6] += CONSTANT(0.139263808033999990) * t;
    y[20] += CONSTANT(0.068480553847200004) * t;
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[8] += CONSTANT(0.141889406570999990) * t;
    y[22] += CONSTANT(0.102084782360000000) * t;

    // [21,23]: 8,22,24,
    tf = CONSTANT(-0.112621225039000000) * f[8] + CONSTANT(0.045015157794100001) * f[22] + CONSTANT(-0.119098912753000000) * f[24];
    tg = CONSTANT(-0.112621225039000000) * g[8] + CONSTANT(0.045015157794100001) * g[22] + CONSTANT(-0.119098912753000000) * g[24];
    y[21] += tf * g[23] + tg * f[23];
    y[23] += tf * g[21] + tg * f[21];
    t = f[21] * g[23] + f[23] * g[21];
    y[8] += CONSTANT(-0.112621225039000000) * t;
    y[22] += CONSTANT(0.045015157794100001) * t;
    y[24] += CONSTANT(-0.119098912753000000) * t;

    // [22,22]: 6,20,0,24,
    tf = CONSTANT(0.065535909662600006) * f[6] + CONSTANT(-0.083698454702400005) * f[20] + CONSTANT(0.282094791771999980) * f[0] + CONSTANT(0.135045473384000000) * f[24];
    tg = CONSTANT(0.065535909662600006) * g[6] + CONSTANT(-0.083698454702400005) * g[20] + CONSTANT(0.282094791771999980) * g[0] + CONSTANT(0.135045473384000000) * g[24];
    y[22] += tf * g[22] + tg * f[22];
    t = f[22] * g[22];
    y[6] += CONSTANT(0.065535909662600006) * t;
    y[20] += CONSTANT(-0.083698454702400005) * t;
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[24] += CONSTANT(0.135045473384000000) * t;

    // [23,23]: 6,20,0,
    tf = CONSTANT(-0.057343920955899998) * f[6] + CONSTANT(-0.159787958979000000) * f[20] + CONSTANT(0.282094791768999990) * f[0];
    tg = CONSTANT(-0.057343920955899998) * g[6] + CONSTANT(-0.159787958979000000) * g[20] + CONSTANT(0.282094791768999990) * g[0];
    y[23] += tf * g[23] + tg * f[23];
    t = f[23] * g[23];
    y[6] += CONSTANT(-0.057343920955899998) * t;
    y[20] += CONSTANT(-0.159787958979000000) * t;
    y[0] += CONSTANT(0.282094791768999990) * t;

    // [24,24]: 6,0,20,
    tf = CONSTANT(-0.229375683829000000) * f[6] + CONSTANT(0.282094791763999990) * f[0] + CONSTANT(0.106525305981000000) * f[20];
    tg = CONSTANT(-0.229375683829000000) * g[6] + CONSTANT(0.282094791763999990) * g[0] + CONSTANT(0.106525305981000000) * g[20];
    y[24] += tf * g[24] + tg * f[24];
    t = f[24] * g[24];
    y[6] += CONSTANT(-0.229375683829000000) * t;
    y[0] += CONSTANT(0.282094791763999990) * t;
    y[20] += CONSTANT(0.106525305981000000) * t;

    // multiply count=1135

    return y;
}

float* STUB_API D3DXSHMultiply6(float* y, const float* f, const float* g)
{
    if (!y || !f || !g)
        return nullptr;

    REAL tf, tg, t;
    // [0,0]: 0,
    y[0] = CONSTANT(0.282094792935999980) * f[0] * g[0];

    // [1,1]: 0,6,8,
    tf = CONSTANT(0.282094791773000010) * f[0] + CONSTANT(-0.126156626101000010) * f[6] + CONSTANT(-0.218509686119999990) * f[8];
    tg = CONSTANT(0.282094791773000010) * g[0] + CONSTANT(-0.126156626101000010) * g[6] + CONSTANT(-0.218509686119999990) * g[8];
    y[1] = tf * g[1] + tg * f[1];
    t = f[1] * g[1];
    y[0] += CONSTANT(0.282094791773000010) * t;
    y[6] = CONSTANT(-0.126156626101000010) * t;
    y[8] = CONSTANT(-0.218509686119999990) * t;

    // [1,4]: 3,13,15,
    tf = CONSTANT(0.218509686114999990) * f[3] + CONSTANT(-0.058399170082300000) * f[13] + CONSTANT(-0.226179013157999990) * f[15];
    tg = CONSTANT(0.218509686114999990) * g[3] + CONSTANT(-0.058399170082300000) * g[13] + CONSTANT(-0.226179013157999990) * g[15];
    y[1] += tf * g[4] + tg * f[4];
    y[4] = tf * g[1] + tg * f[1];
    t = f[1] * g[4] + f[4] * g[1];
    y[3] = CONSTANT(0.218509686114999990) * t;
    y[13] = CONSTANT(-0.058399170082300000) * t;
    y[15] = CONSTANT(-0.226179013157999990) * t;

    // [1,5]: 2,12,
    tf = CONSTANT(0.218509686118000010) * f[2] + CONSTANT(-0.143048168103000000) * f[12];
    tg = CONSTANT(0.218509686118000010) * g[2] + CONSTANT(-0.143048168103000000) * g[12];
    y[1] += tf * g[5] + tg * f[5];
    y[5] = tf * g[1] + tg * f[1];
    t = f[1] * g[5] + f[5] * g[1];
    y[2] = CONSTANT(0.218509686118000010) * t;
    y[12] = CONSTANT(-0.143048168103000000) * t;

    // [1,11]: 6,8,20,22,
    tf = CONSTANT(0.202300659402999990) * f[6] + CONSTANT(0.058399170081799998) * f[8] + CONSTANT(-0.150786008773000000) * f[20] + CONSTANT(-0.168583882836999990) * f[22];
    tg = CONSTANT(0.202300659402999990) * g[6] + CONSTANT(0.058399170081799998) * g[8] + CONSTANT(-0.150786008773000000) * g[20] + CONSTANT(-0.168583882836999990) * g[22];
    y[1] += tf * g[11] + tg * f[11];
    y[11] = tf * g[1] + tg * f[1];
    t = f[1] * g[11] + f[11] * g[1];
    y[6] += CONSTANT(0.202300659402999990) * t;
    y[8] += CONSTANT(0.058399170081799998) * t;
    y[20] = CONSTANT(-0.150786008773000000) * t;
    y[22] = CONSTANT(-0.168583882836999990) * t;

    // [1,16]: 15,33,35,
    tf = CONSTANT(0.230329432973999990) * f[15] + CONSTANT(-0.034723468517399998) * f[33] + CONSTANT(-0.232932108051999990) * f[35];
    tg = CONSTANT(0.230329432973999990) * g[15] + CONSTANT(-0.034723468517399998) * g[33] + CONSTANT(-0.232932108051999990) * g[35];
    y[1] += tf * g[16] + tg * f[16];
    y[16] = tf * g[1] + tg * f[1];
    t = f[1] * g[16] + f[16] * g[1];
    y[15] += CONSTANT(0.230329432973999990) * t;
    y[33] = CONSTANT(-0.034723468517399998) * t;
    y[35] = CONSTANT(-0.232932108051999990) * t;

    // [1,18]: 15,13,31,33,
    tf = CONSTANT(0.043528171377799997) * f[15] + CONSTANT(0.168583882834000000) * f[13] + CONSTANT(-0.085054779966799998) * f[31] + CONSTANT(-0.183739324705999990) * f[33];
    tg = CONSTANT(0.043528171377799997) * g[15] + CONSTANT(0.168583882834000000) * g[13] + CONSTANT(-0.085054779966799998) * g[31] + CONSTANT(-0.183739324705999990) * g[33];
    y[1] += tf * g[18] + tg * f[18];
    y[18] = tf * g[1] + tg * f[1];
    t = f[1] * g[18] + f[18] * g[1];
    y[15] += CONSTANT(0.043528171377799997) * t;
    y[13] += CONSTANT(0.168583882834000000) * t;
    y[31] = CONSTANT(-0.085054779966799998) * t;
    y[33] += CONSTANT(-0.183739324705999990) * t;

    // [1,19]: 14,12,30,32,
    tf = CONSTANT(0.075393004386399995) * f[14] + CONSTANT(0.194663900273000010) * f[12] + CONSTANT(-0.155288072037000010) * f[30] + CONSTANT(-0.159122922869999990) * f[32];
    tg = CONSTANT(0.075393004386399995) * g[14] + CONSTANT(0.194663900273000010) * g[12] + CONSTANT(-0.155288072037000010) * g[30] + CONSTANT(-0.159122922869999990) * g[32];
    y[1] += tf * g[19] + tg * f[19];
    y[19] = tf * g[1] + tg * f[1];
    t = f[1] * g[19] + f[19] * g[1];
    y[14] = CONSTANT(0.075393004386399995) * t;
    y[12] += CONSTANT(0.194663900273000010) * t;
    y[30] = CONSTANT(-0.155288072037000010) * t;
    y[32] = CONSTANT(-0.159122922869999990) * t;

    // [1,24]: 9,25,27,
    tf = CONSTANT(-0.230329432978999990) * f[9] + CONSTANT(0.232932108049000000) * f[25] + CONSTANT(0.034723468517100002) * f[27];
    tg = CONSTANT(-0.230329432978999990) * g[9] + CONSTANT(0.232932108049000000) * g[25] + CONSTANT(0.034723468517100002) * g[27];
    y[1] += tf * g[24] + tg * f[24];
    y[24] = tf * g[1] + tg * f[1];
    t = f[1] * g[24] + f[24] * g[1];
    y[9] = CONSTANT(-0.230329432978999990) * t;
    y[25] = CONSTANT(0.232932108049000000) * t;
    y[27] = CONSTANT(0.034723468517100002) * t;

    // [1,29]: 22,20,
    tf = CONSTANT(0.085054779965999999) * f[22] + CONSTANT(0.190188269815000010) * f[20];
    tg = CONSTANT(0.085054779965999999) * g[22] + CONSTANT(0.190188269815000010) * g[20];
    y[1] += tf * g[29] + tg * f[29];
    y[29] = tf * g[1] + tg * f[1];
    t = f[1] * g[29] + f[29] * g[1];
    y[22] += CONSTANT(0.085054779965999999) * t;
    y[20] += CONSTANT(0.190188269815000010) * t;

    // [2,2]: 0,6,
    tf = CONSTANT(0.282094795249000000) * f[0] + CONSTANT(0.252313259986999990) * f[6];
    tg = CONSTANT(0.282094795249000000) * g[0] + CONSTANT(0.252313259986999990) * g[6];
    y[2] += tf * g[2] + tg * f[2];
    t = f[2] * g[2];
    y[0] += CONSTANT(0.282094795249000000) * t;
    y[6] += CONSTANT(0.252313259986999990) * t;

    // [2,12]: 6,20,
    tf = CONSTANT(0.247766706973999990) * f[6] + CONSTANT(0.246232537174000010) * f[20];
    tg = CONSTANT(0.247766706973999990) * g[6] + CONSTANT(0.246232537174000010) * g[20];
    y[2] += tf * g[12] + tg * f[12];
    y[12] += tf * g[2] + tg * f[2];
    t = f[2] * g[12] + f[12] * g[2];
    y[6] += CONSTANT(0.247766706973999990) * t;
    y[20] += CONSTANT(0.246232537174000010) * t;

    // [2,20]: 30,
    tf = CONSTANT(0.245532020560000010) * f[30];
    tg = CONSTANT(0.245532020560000010) * g[30];
    y[2] += tf * g[20] + tg * f[20];
    y[20] += tf * g[2] + tg * f[2];
    t = f[2] * g[20] + f[20] * g[2];
    y[30] += CONSTANT(0.245532020560000010) * t;

    // [3,3]: 0,6,8,
    tf = CONSTANT(0.282094791773000010) * f[0] + CONSTANT(-0.126156626101000010) * f[6] + CONSTANT(0.218509686119999990) * f[8];
    tg = CONSTANT(0.282094791773000010) * g[0] + CONSTANT(-0.126156626101000010) * g[6] + CONSTANT(0.218509686119999990) * g[8];
    y[3] += tf * g[3] + tg * f[3];
    t = f[3] * g[3];
    y[0] += CONSTANT(0.282094791773000010) * t;
    y[6] += CONSTANT(-0.126156626101000010) * t;
    y[8] += CONSTANT(0.218509686119999990) * t;

    // [3,7]: 2,12,
    tf = CONSTANT(0.218509686118000010) * f[2] + CONSTANT(-0.143048168103000000) * f[12];
    tg = CONSTANT(0.218509686118000010) * g[2] + CONSTANT(-0.143048168103000000) * g[12];
    y[3] += tf * g[7] + tg * f[7];
    y[7] = tf * g[3] + tg * f[3];
    t = f[3] * g[7] + f[7] * g[3];
    y[2] += CONSTANT(0.218509686118000010) * t;
    y[12] += CONSTANT(-0.143048168103000000) * t;

    // [3,13]: 8,6,20,22,
    tf = CONSTANT(-0.058399170081799998) * f[8] + CONSTANT(0.202300659402999990) * f[6] + CONSTANT(-0.150786008773000000) * f[20] + CONSTANT(0.168583882836999990) * f[22];
    tg = CONSTANT(-0.058399170081799998) * g[8] + CONSTANT(0.202300659402999990) * g[6] + CONSTANT(-0.150786008773000000) * g[20] + CONSTANT(0.168583882836999990) * g[22];
    y[3] += tf * g[13] + tg * f[13];
    y[13] += tf * g[3] + tg * f[3];
    t = f[3] * g[13] + f[13] * g[3];
    y[8] += CONSTANT(-0.058399170081799998) * t;
    y[6] += CONSTANT(0.202300659402999990) * t;
    y[20] += CONSTANT(-0.150786008773000000) * t;
    y[22] += CONSTANT(0.168583882836999990) * t;

    // [3,16]: 9,25,27,
    tf = CONSTANT(0.230329432973999990) * f[9] + CONSTANT(0.232932108051999990) * f[25] + CONSTANT(-0.034723468517399998) * f[27];
    tg = CONSTANT(0.230329432973999990) * g[9] + CONSTANT(0.232932108051999990) * g[25] + CONSTANT(-0.034723468517399998) * g[27];
    y[3] += tf * g[16] + tg * f[16];
    y[16] += tf * g[3] + tg * f[3];
    t = f[3] * g[16] + f[16] * g[3];
    y[9] += CONSTANT(0.230329432973999990) * t;
    y[25] += CONSTANT(0.232932108051999990) * t;
    y[27] += CONSTANT(-0.034723468517399998) * t;

    // [3,21]: 12,14,30,32,
    tf = CONSTANT(0.194663900273000010) * f[12] + CONSTANT(-0.075393004386399995) * f[14] + CONSTANT(-0.155288072037000010) * f[30] + CONSTANT(0.159122922869999990) * f[32];
    tg = CONSTANT(0.194663900273000010) * g[12] + CONSTANT(-0.075393004386399995) * g[14] + CONSTANT(-0.155288072037000010) * g[30] + CONSTANT(0.159122922869999990) * g[32];
    y[3] += tf * g[21] + tg * f[21];
    y[21] = tf * g[3] + tg * f[3];
    t = f[3] * g[21] + f[21] * g[3];
    y[12] += CONSTANT(0.194663900273000010) * t;
    y[14] += CONSTANT(-0.075393004386399995) * t;
    y[30] += CONSTANT(-0.155288072037000010) * t;
    y[32] += CONSTANT(0.159122922869999990) * t;

    // [3,24]: 15,33,35,
    tf = CONSTANT(0.230329432978999990) * f[15] + CONSTANT(-0.034723468517100002) * f[33] + CONSTANT(0.232932108049000000) * f[35];
    tg = CONSTANT(0.230329432978999990) * g[15] + CONSTANT(-0.034723468517100002) * g[33] + CONSTANT(0.232932108049000000) * g[35];
    y[3] += tf * g[24] + tg * f[24];
    y[24] += tf * g[3] + tg * f[3];
    t = f[3] * g[24] + f[24] * g[3];
    y[15] += CONSTANT(0.230329432978999990) * t;
    y[33] += CONSTANT(-0.034723468517100002) * t;
    y[35] += CONSTANT(0.232932108049000000) * t;

    // [3,31]: 20,22,
    tf = CONSTANT(0.190188269815000010) * f[20] + CONSTANT(-0.085054779965999999) * f[22];
    tg = CONSTANT(0.190188269815000010) * g[20] + CONSTANT(-0.085054779965999999) * g[22];
    y[3] += tf * g[31] + tg * f[31];
    y[31] += tf * g[3] + tg * f[3];
    t = f[3] * g[31] + f[31] * g[3];
    y[20] += CONSTANT(0.190188269815000010) * t;
    y[22] += CONSTANT(-0.085054779965999999) * t;

    // [4,4]: 0,6,20,24,
    tf = CONSTANT(0.282094791770000020) * f[0] + CONSTANT(-0.180223751576000010) * f[6] + CONSTANT(0.040299255967500003) * f[20] + CONSTANT(-0.238413613505999990) * f[24];
    tg = CONSTANT(0.282094791770000020) * g[0] + CONSTANT(-0.180223751576000010) * g[6] + CONSTANT(0.040299255967500003) * g[20] + CONSTANT(-0.238413613505999990) * g[24];
    y[4] += tf * g[4] + tg * f[4];
    t = f[4] * g[4];
    y[0] += CONSTANT(0.282094791770000020) * t;
    y[6] += CONSTANT(-0.180223751576000010) * t;
    y[20] += CONSTANT(0.040299255967500003) * t;
    y[24] += CONSTANT(-0.238413613505999990) * t;

    // [4,5]: 7,21,23,
    tf = CONSTANT(0.156078347226000000) * f[7] + CONSTANT(-0.063718718434399996) * f[21] + CONSTANT(-0.168583882835000000) * f[23];
    tg = CONSTANT(0.156078347226000000) * g[7] + CONSTANT(-0.063718718434399996) * g[21] + CONSTANT(-0.168583882835000000) * g[23];
    y[4] += tf * g[5] + tg * f[5];
    y[5] += tf * g[4] + tg * f[4];
    t = f[4] * g[5] + f[5] * g[4];
    y[7] += CONSTANT(0.156078347226000000) * t;
    y[21] += CONSTANT(-0.063718718434399996) * t;
    y[23] = CONSTANT(-0.168583882835000000) * t;

    // [4,9]: 3,13,31,35,
    tf = CONSTANT(0.226179013157999990) * f[3] + CONSTANT(-0.094031597258400004) * f[13] + CONSTANT(0.016943317729299998) * f[31] + CONSTANT(-0.245532000542000000) * f[35];
    tg = CONSTANT(0.226179013157999990) * g[3] + CONSTANT(-0.094031597258400004) * g[13] + CONSTANT(0.016943317729299998) * g[31] + CONSTANT(-0.245532000542000000) * g[35];
    y[4] += tf * g[9] + tg * f[9];
    y[9] += tf * g[4] + tg * f[4];
    t = f[4] * g[9] + f[9] * g[4];
    y[3] += CONSTANT(0.226179013157999990) * t;
    y[13] += CONSTANT(-0.094031597258400004) * t;
    y[31] += CONSTANT(0.016943317729299998) * t;
    y[35] += CONSTANT(-0.245532000542000000) * t;

    // [4,10]: 2,12,30,34,
    tf = CONSTANT(0.184674390919999990) * f[2] + CONSTANT(-0.188063194517999990) * f[12] + CONSTANT(0.053579475144400000) * f[30] + CONSTANT(-0.190188269816000010) * f[34];
    tg = CONSTANT(0.184674390919999990) * g[2] + CONSTANT(-0.188063194517999990) * g[12] + CONSTANT(0.053579475144400000) * g[30] + CONSTANT(-0.190188269816000010) * g[34];
    y[4] += tf * g[10] + tg * f[10];
    y[10] = tf * g[4] + tg * f[4];
    t = f[4] * g[10] + f[10] * g[4];
    y[2] += CONSTANT(0.184674390919999990) * t;
    y[12] += CONSTANT(-0.188063194517999990) * t;
    y[30] += CONSTANT(0.053579475144400000) * t;
    y[34] = CONSTANT(-0.190188269816000010) * t;

    // [4,11]: 3,13,15,31,33,
    tf = CONSTANT(-0.058399170082300000) * f[3] + CONSTANT(0.145673124078000010) * f[13] + CONSTANT(0.094031597258400004) * f[15] + CONSTANT(-0.065621187395699998) * f[31] + CONSTANT(-0.141757966610000010) * f[33];
    tg = CONSTANT(-0.058399170082300000) * g[3] + CONSTANT(0.145673124078000010) * g[13] + CONSTANT(0.094031597258400004) * g[15] + CONSTANT(-0.065621187395699998) * g[31] + CONSTANT(-0.141757966610000010) * g[33];
    y[4] += tf * g[11] + tg * f[11];
    y[11] += tf * g[4] + tg * f[4];
    t = f[4] * g[11] + f[11] * g[4];
    y[3] += CONSTANT(-0.058399170082300000) * t;
    y[13] += CONSTANT(0.145673124078000010) * t;
    y[15] += CONSTANT(0.094031597258400004) * t;
    y[31] += CONSTANT(-0.065621187395699998) * t;
    y[33] += CONSTANT(-0.141757966610000010) * t;

    // [4,16]: 8,22,
    tf = CONSTANT(0.238413613494000000) * f[8] + CONSTANT(-0.075080816693699995) * f[22];
    tg = CONSTANT(0.238413613494000000) * g[8] + CONSTANT(-0.075080816693699995) * g[22];
    y[4] += tf * g[16] + tg * f[16];
    y[16] += tf * g[4] + tg * f[4];
    t = f[4] * g[16] + f[16] * g[4];
    y[8] += CONSTANT(0.238413613494000000) * t;
    y[22] += CONSTANT(-0.075080816693699995) * t;

    // [4,18]: 6,20,24,
    tf = CONSTANT(0.156078347226000000) * f[6] + CONSTANT(-0.190364615029000010) * f[20] + CONSTANT(0.075080816691500005) * f[24];
    tg = CONSTANT(0.156078347226000000) * g[6] + CONSTANT(-0.190364615029000010) * g[20] + CONSTANT(0.075080816691500005) * g[24];
    y[4] += tf * g[18] + tg * f[18];
    y[18] += tf * g[4] + tg * f[4];
    t = f[4] * g[18] + f[18] * g[4];
    y[6] += CONSTANT(0.156078347226000000) * t;
    y[20] += CONSTANT(-0.190364615029000010) * t;
    y[24] += CONSTANT(0.075080816691500005) * t;

    // [4,19]: 7,21,23,
    tf = CONSTANT(-0.063718718434399996) * f[7] + CONSTANT(0.141889406569999990) * f[21] + CONSTANT(0.112621225039000000) * f[23];
    tg = CONSTANT(-0.063718718434399996) * g[7] + CONSTANT(0.141889406569999990) * g[21] + CONSTANT(0.112621225039000000) * g[23];
    y[4] += tf * g[19] + tg * f[19];
    y[19] += tf * g[4] + tg * f[4];
    t = f[4] * g[19] + f[19] * g[4];
    y[7] += CONSTANT(-0.063718718434399996) * t;
    y[21] += CONSTANT(0.141889406569999990) * t;
    y[23] += CONSTANT(0.112621225039000000) * t;

    // [4,25]: 15,33,
    tf = CONSTANT(0.245532000542000000) * f[15] + CONSTANT(-0.062641347680800000) * f[33];
    tg = CONSTANT(0.245532000542000000) * g[15] + CONSTANT(-0.062641347680800000) * g[33];
    y[4] += tf * g[25] + tg * f[25];
    y[25] += tf * g[4] + tg * f[4];
    t = f[4] * g[25] + f[25] * g[4];
    y[15] += CONSTANT(0.245532000542000000) * t;
    y[33] += CONSTANT(-0.062641347680800000) * t;

    // [4,26]: 14,32,
    tf = CONSTANT(0.190188269806999990) * f[14] + CONSTANT(-0.097043558542400002) * f[32];
    tg = CONSTANT(0.190188269806999990) * g[14] + CONSTANT(-0.097043558542400002) * g[32];
    y[4] += tf * g[26] + tg * f[26];
    y[26] = tf * g[4] + tg * f[4];
    t = f[4] * g[26] + f[26] * g[4];
    y[14] += CONSTANT(0.190188269806999990) * t;
    y[32] += CONSTANT(-0.097043558542400002) * t;

    // [4,27]: 13,31,35,
    tf = CONSTANT(0.141757966610000010) * f[13] + CONSTANT(-0.121034582549000000) * f[31] + CONSTANT(0.062641347680800000) * f[35];
    tg = CONSTANT(0.141757966610000010) * g[13] + CONSTANT(-0.121034582549000000) * g[31] + CONSTANT(0.062641347680800000) * g[35];
    y[4] += tf * g[27] + tg * f[27];
    y[27] += tf * g[4] + tg * f[4];
    t = f[4] * g[27] + f[27] * g[4];
    y[13] += CONSTANT(0.141757966610000010) * t;
    y[31] += CONSTANT(-0.121034582549000000) * t;
    y[35] += CONSTANT(0.062641347680800000) * t;

    // [4,28]: 12,30,34,
    tf = CONSTANT(0.141757966609000000) * f[12] + CONSTANT(-0.191372478254000000) * f[30] + CONSTANT(0.097043558538899996) * f[34];
    tg = CONSTANT(0.141757966609000000) * g[12] + CONSTANT(-0.191372478254000000) * g[30] + CONSTANT(0.097043558538899996) * g[34];
    y[4] += tf * g[28] + tg * f[28];
    y[28] = tf * g[4] + tg * f[4];
    t = f[4] * g[28] + f[28] * g[4];
    y[12] += CONSTANT(0.141757966609000000) * t;
    y[30] += CONSTANT(-0.191372478254000000) * t;
    y[34] += CONSTANT(0.097043558538899996) * t;

    // [4,29]: 13,15,31,33,
    tf = CONSTANT(-0.065621187395699998) * f[13] + CONSTANT(-0.016943317729299998) * f[15] + CONSTANT(0.140070311613999990) * f[31] + CONSTANT(0.121034582549000000) * f[33];
    tg = CONSTANT(-0.065621187395699998) * g[13] + CONSTANT(-0.016943317729299998) * g[15] + CONSTANT(0.140070311613999990) * g[31] + CONSTANT(0.121034582549000000) * g[33];
    y[4] += tf * g[29] + tg * f[29];
    y[29] += tf * g[4] + tg * f[4];
    t = f[4] * g[29] + f[29] * g[4];
    y[13] += CONSTANT(-0.065621187395699998) * t;
    y[15] += CONSTANT(-0.016943317729299998) * t;
    y[31] += CONSTANT(0.140070311613999990) * t;
    y[33] += CONSTANT(0.121034582549000000) * t;

    // [5,5]: 0,6,8,20,22,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.090111875786499998) * f[6] + CONSTANT(-0.156078347227999990) * f[8] + CONSTANT(-0.161197023870999990) * f[20] + CONSTANT(-0.180223751574000000) * f[22];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.090111875786499998) * g[6] + CONSTANT(-0.156078347227999990) * g[8] + CONSTANT(-0.161197023870999990) * g[20] + CONSTANT(-0.180223751574000000) * g[22];
    y[5] += tf * g[5] + tg * f[5];
    t = f[5] * g[5];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[6] += CONSTANT(0.090111875786499998) * t;
    y[8] += CONSTANT(-0.156078347227999990) * t;
    y[20] += CONSTANT(-0.161197023870999990) * t;
    y[22] += CONSTANT(-0.180223751574000000) * t;

    // [5,10]: 3,13,15,31,33,
    tf = CONSTANT(0.184674390919999990) * f[3] + CONSTANT(0.115164716490000000) * f[13] + CONSTANT(-0.148677009678999990) * f[15] + CONSTANT(-0.083004965974099995) * f[31] + CONSTANT(-0.179311220383999990) * f[33];
    tg = CONSTANT(0.184674390919999990) * g[3] + CONSTANT(0.115164716490000000) * g[13] + CONSTANT(-0.148677009678999990) * g[15] + CONSTANT(-0.083004965974099995) * g[31] + CONSTANT(-0.179311220383999990) * g[33];
    y[5] += tf * g[10] + tg * f[10];
    y[10] += tf * g[5] + tg * f[5];
    t = f[5] * g[10] + f[10] * g[5];
    y[3] += CONSTANT(0.184674390919999990) * t;
    y[13] += CONSTANT(0.115164716490000000) * t;
    y[15] += CONSTANT(-0.148677009678999990) * t;
    y[31] += CONSTANT(-0.083004965974099995) * t;
    y[33] += CONSTANT(-0.179311220383999990) * t;

    // [5,11]: 2,12,14,30,32,
    tf = CONSTANT(0.233596680327000010) * f[2] + CONSTANT(0.059470803871800003) * f[12] + CONSTANT(-0.115164716491000000) * f[14] + CONSTANT(-0.169433177294000010) * f[30] + CONSTANT(-0.173617342585000000) * f[32];
    tg = CONSTANT(0.233596680327000010) * g[2] + CONSTANT(0.059470803871800003) * g[12] + CONSTANT(-0.115164716491000000) * g[14] + CONSTANT(-0.169433177294000010) * g[30] + CONSTANT(-0.173617342585000000) * g[32];
    y[5] += tf * g[11] + tg * f[11];
    y[11] += tf * g[5] + tg * f[5];
    t = f[5] * g[11] + f[11] * g[5];
    y[2] += CONSTANT(0.233596680327000010) * t;
    y[12] += CONSTANT(0.059470803871800003) * t;
    y[14] += CONSTANT(-0.115164716491000000) * t;
    y[30] += CONSTANT(-0.169433177294000010) * t;
    y[32] += CONSTANT(-0.173617342585000000) * t;

    // [5,14]: 9,1,27,29,
    tf = CONSTANT(0.148677009677999990) * f[9] + CONSTANT(-0.184674390923000000) * f[1] + CONSTANT(0.179311220382000010) * f[27] + CONSTANT(0.083004965973399999) * f[29];
    tg = CONSTANT(0.148677009677999990) * g[9] + CONSTANT(-0.184674390923000000) * g[1] + CONSTANT(0.179311220382000010) * g[27] + CONSTANT(0.083004965973399999) * g[29];
    y[5] += tf * g[14] + tg * f[14];
    y[14] += tf * g[5] + tg * f[5];
    t = f[5] * g[14] + f[14] * g[5];
    y[9] += CONSTANT(0.148677009677999990) * t;
    y[1] += CONSTANT(-0.184674390923000000) * t;
    y[27] += CONSTANT(0.179311220382000010) * t;
    y[29] += CONSTANT(0.083004965973399999) * t;

    // [5,17]: 8,22,24,
    tf = CONSTANT(0.168583882832999990) * f[8] + CONSTANT(0.132725386548000010) * f[22] + CONSTANT(-0.140463346189000000) * f[24];
    tg = CONSTANT(0.168583882832999990) * g[8] + CONSTANT(0.132725386548000010) * g[22] + CONSTANT(-0.140463346189000000) * g[24];
    y[5] += tf * g[17] + tg * f[17];
    y[17] = tf * g[5] + tg * f[5];
    t = f[5] * g[17] + f[17] * g[5];
    y[8] += CONSTANT(0.168583882832999990) * t;
    y[22] += CONSTANT(0.132725386548000010) * t;
    y[24] += CONSTANT(-0.140463346189000000) * t;

    // [5,18]: 7,21,23,
    tf = CONSTANT(0.180223751571000010) * f[7] + CONSTANT(0.090297865407399994) * f[21] + CONSTANT(-0.132725386549000010) * f[23];
    tg = CONSTANT(0.180223751571000010) * g[7] + CONSTANT(0.090297865407399994) * g[21] + CONSTANT(-0.132725386549000010) * g[23];
    y[5] += tf * g[18] + tg * f[18];
    y[18] += tf * g[5] + tg * f[5];
    t = f[5] * g[18] + f[18] * g[5];
    y[7] += CONSTANT(0.180223751571000010) * t;
    y[21] += CONSTANT(0.090297865407399994) * t;
    y[23] += CONSTANT(-0.132725386549000010) * t;

    // [5,19]: 6,8,20,22,
    tf = CONSTANT(0.220728115440999990) * f[6] + CONSTANT(0.063718718433900007) * f[8] + CONSTANT(0.044869370061299998) * f[20] + CONSTANT(-0.090297865408399999) * f[22];
    tg = CONSTANT(0.220728115440999990) * g[6] + CONSTANT(0.063718718433900007) * g[8] + CONSTANT(0.044869370061299998) * g[20] + CONSTANT(-0.090297865408399999) * g[22];
    y[5] += tf * g[19] + tg * f[19];
    y[19] += tf * g[5] + tg * f[5];
    t = f[5] * g[19] + f[19] * g[5];
    y[6] += CONSTANT(0.220728115440999990) * t;
    y[8] += CONSTANT(0.063718718433900007) * t;
    y[20] += CONSTANT(0.044869370061299998) * t;
    y[22] += CONSTANT(-0.090297865408399999) * t;

    // [5,26]: 15,33,35,
    tf = CONSTANT(0.155288072035000000) * f[15] + CONSTANT(0.138662534056999990) * f[33] + CONSTANT(-0.132882365179999990) * f[35];
    tg = CONSTANT(0.155288072035000000) * g[15] + CONSTANT(0.138662534056999990) * g[33] + CONSTANT(-0.132882365179999990) * g[35];
    y[5] += tf * g[26] + tg * f[26];
    y[26] += tf * g[5] + tg * f[5];
    t = f[5] * g[26] + f[26] * g[5];
    y[15] += CONSTANT(0.155288072035000000) * t;
    y[33] += CONSTANT(0.138662534056999990) * t;
    y[35] += CONSTANT(-0.132882365179999990) * t;

    // [5,28]: 15,13,31,33,
    tf = CONSTANT(0.044827805096399997) * f[15] + CONSTANT(0.173617342584000000) * f[13] + CONSTANT(0.074118242118699995) * f[31] + CONSTANT(-0.114366930522000000) * f[33];
    tg = CONSTANT(0.044827805096399997) * g[15] + CONSTANT(0.173617342584000000) * g[13] + CONSTANT(0.074118242118699995) * g[31] + CONSTANT(-0.114366930522000000) * g[33];
    y[5] += tf * g[28] + tg * f[28];
    y[28] += tf * g[5] + tg * f[5];
    t = f[5] * g[28] + f[28] * g[5];
    y[15] += CONSTANT(0.044827805096399997) * t;
    y[13] += CONSTANT(0.173617342584000000) * t;
    y[31] += CONSTANT(0.074118242118699995) * t;
    y[33] += CONSTANT(-0.114366930522000000) * t;

    // [5,29]: 12,30,32,
    tf = CONSTANT(0.214317900578999990) * f[12] + CONSTANT(0.036165998945399999) * f[30] + CONSTANT(-0.074118242119099995) * f[32];
    tg = CONSTANT(0.214317900578999990) * g[12] + CONSTANT(0.036165998945399999) * g[30] + CONSTANT(-0.074118242119099995) * g[32];
    y[5] += tf * g[29] + tg * f[29];
    y[29] += tf * g[5] + tg * f[5];
    t = f[5] * g[29] + f[29] * g[5];
    y[12] += CONSTANT(0.214317900578999990) * t;
    y[30] += CONSTANT(0.036165998945399999) * t;
    y[32] += CONSTANT(-0.074118242119099995) * t;

    // [5,32]: 9,27,
    tf = CONSTANT(-0.044827805096799997) * f[9] + CONSTANT(0.114366930522000000) * f[27];
    tg = CONSTANT(-0.044827805096799997) * g[9] + CONSTANT(0.114366930522000000) * g[27];
    y[5] += tf * g[32] + tg * f[32];
    y[32] += tf * g[5] + tg * f[5];
    t = f[5] * g[32] + f[32] * g[5];
    y[9] += CONSTANT(-0.044827805096799997) * t;
    y[27] += CONSTANT(0.114366930522000000) * t;

    // [5,34]: 9,27,25,
    tf = CONSTANT(-0.155288072036000010) * f[9] + CONSTANT(-0.138662534059000000) * f[27] + CONSTANT(0.132882365179000010) * f[25];
    tg = CONSTANT(-0.155288072036000010) * g[9] + CONSTANT(-0.138662534059000000) * g[27] + CONSTANT(0.132882365179000010) * g[25];
    y[5] += tf * g[34] + tg * f[34];
    y[34] += tf * g[5] + tg * f[5];
    t = f[5] * g[34] + f[34] * g[5];
    y[9] += CONSTANT(-0.155288072036000010) * t;
    y[27] += CONSTANT(-0.138662534059000000) * t;
    y[25] += CONSTANT(0.132882365179000010) * t;

    // [6,6]: 0,6,20,
    tf = CONSTANT(0.282094797560000000) * f[0] + CONSTANT(0.241795553185999990) * f[20];
    tg = CONSTANT(0.282094797560000000) * g[0] + CONSTANT(0.241795553185999990) * g[20];
    y[6] += tf * g[6] + tg * f[6];
    t = f[6] * g[6];
    y[0] += CONSTANT(0.282094797560000000) * t;
    y[6] += CONSTANT(0.180223764527000010) * t;
    y[20] += CONSTANT(0.241795553185999990) * t;

    // [7,7]: 6,0,8,20,22,
    tf = CONSTANT(0.090111875786499998) * f[6] + CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.156078347227999990) * f[8] + CONSTANT(-0.161197023870999990) * f[20] + CONSTANT(0.180223751574000000) * f[22];
    tg = CONSTANT(0.090111875786499998) * g[6] + CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.156078347227999990) * g[8] + CONSTANT(-0.161197023870999990) * g[20] + CONSTANT(0.180223751574000000) * g[22];
    y[7] += tf * g[7] + tg * f[7];
    t = f[7] * g[7];
    y[6] += CONSTANT(0.090111875786499998) * t;
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[8] += CONSTANT(0.156078347227999990) * t;
    y[20] += CONSTANT(-0.161197023870999990) * t;
    y[22] += CONSTANT(0.180223751574000000) * t;

    // [7,10]: 9,1,11,27,29,
    tf = CONSTANT(0.148677009678999990) * f[9] + CONSTANT(0.184674390919999990) * f[1] + CONSTANT(0.115164716490000000) * f[11] + CONSTANT(0.179311220383999990) * f[27] + CONSTANT(-0.083004965974099995) * f[29];
    tg = CONSTANT(0.148677009678999990) * g[9] + CONSTANT(0.184674390919999990) * g[1] + CONSTANT(0.115164716490000000) * g[11] + CONSTANT(0.179311220383999990) * g[27] + CONSTANT(-0.083004965974099995) * g[29];
    y[7] += tf * g[10] + tg * f[10];
    y[10] += tf * g[7] + tg * f[7];
    t = f[7] * g[10] + f[10] * g[7];
    y[9] += CONSTANT(0.148677009678999990) * t;
    y[1] += CONSTANT(0.184674390919999990) * t;
    y[11] += CONSTANT(0.115164716490000000) * t;
    y[27] += CONSTANT(0.179311220383999990) * t;
    y[29] += CONSTANT(-0.083004965974099995) * t;

    // [7,13]: 12,2,14,30,32,
    tf = CONSTANT(0.059470803871800003) * f[12] + CONSTANT(0.233596680327000010) * f[2] + CONSTANT(0.115164716491000000) * f[14] + CONSTANT(-0.169433177294000010) * f[30] + CONSTANT(0.173617342585000000) * f[32];
    tg = CONSTANT(0.059470803871800003) * g[12] + CONSTANT(0.233596680327000010) * g[2] + CONSTANT(0.115164716491000000) * g[14] + CONSTANT(-0.169433177294000010) * g[30] + CONSTANT(0.173617342585000000) * g[32];
    y[7] += tf * g[13] + tg * f[13];
    y[13] += tf * g[7] + tg * f[7];
    t = f[7] * g[13] + f[13] * g[7];
    y[12] += CONSTANT(0.059470803871800003) * t;
    y[2] += CONSTANT(0.233596680327000010) * t;
    y[14] += CONSTANT(0.115164716491000000) * t;
    y[30] += CONSTANT(-0.169433177294000010) * t;
    y[32] += CONSTANT(0.173617342585000000) * t;

    // [7,14]: 3,15,31,33,
    tf = CONSTANT(0.184674390923000000) * f[3] + CONSTANT(0.148677009677999990) * f[15] + CONSTANT(-0.083004965973399999) * f[31] + CONSTANT(0.179311220382000010) * f[33];
    tg = CONSTANT(0.184674390923000000) * g[3] + CONSTANT(0.148677009677999990) * g[15] + CONSTANT(-0.083004965973399999) * g[31] + CONSTANT(0.179311220382000010) * g[33];
    y[7] += tf * g[14] + tg * f[14];
    y[14] += tf * g[7] + tg * f[7];
    t = f[7] * g[14] + f[14] * g[7];
    y[3] += CONSTANT(0.184674390923000000) * t;
    y[15] += CONSTANT(0.148677009677999990) * t;
    y[31] += CONSTANT(-0.083004965973399999) * t;
    y[33] += CONSTANT(0.179311220382000010) * t;

    // [7,17]: 16,4,18,
    tf = CONSTANT(0.140463346187999990) * f[16] + CONSTANT(0.168583882835000000) * f[4] + CONSTANT(0.132725386549000010) * f[18];
    tg = CONSTANT(0.140463346187999990) * g[16] + CONSTANT(0.168583882835000000) * g[4] + CONSTANT(0.132725386549000010) * g[18];
    y[7] += tf * g[17] + tg * f[17];
    y[17] += tf * g[7] + tg * f[7];
    t = f[7] * g[17] + f[17] * g[7];
    y[16] += CONSTANT(0.140463346187999990) * t;
    y[4] += CONSTANT(0.168583882835000000) * t;
    y[18] += CONSTANT(0.132725386549000010) * t;

    // [7,21]: 8,20,6,22,
    tf = CONSTANT(-0.063718718433900007) * f[8] + CONSTANT(0.044869370061299998) * f[20] + CONSTANT(0.220728115440999990) * f[6] + CONSTANT(0.090297865408399999) * f[22];
    tg = CONSTANT(-0.063718718433900007) * g[8] + CONSTANT(0.044869370061299998) * g[20] + CONSTANT(0.220728115440999990) * g[6] + CONSTANT(0.090297865408399999) * g[22];
    y[7] += tf * g[21] + tg * f[21];
    y[21] += tf * g[7] + tg * f[7];
    t = f[7] * g[21] + f[21] * g[7];
    y[8] += CONSTANT(-0.063718718433900007) * t;
    y[20] += CONSTANT(0.044869370061299998) * t;
    y[6] += CONSTANT(0.220728115440999990) * t;
    y[22] += CONSTANT(0.090297865408399999) * t;

    // [7,23]: 8,22,24,
    tf = CONSTANT(0.168583882832999990) * f[8] + CONSTANT(0.132725386548000010) * f[22] + CONSTANT(0.140463346189000000) * f[24];
    tg = CONSTANT(0.168583882832999990) * g[8] + CONSTANT(0.132725386548000010) * g[22] + CONSTANT(0.140463346189000000) * g[24];
    y[7] += tf * g[23] + tg * f[23];
    y[23] += tf * g[7] + tg * f[7];
    t = f[7] * g[23] + f[23] * g[7];
    y[8] += CONSTANT(0.168583882832999990) * t;
    y[22] += CONSTANT(0.132725386548000010) * t;
    y[24] += CONSTANT(0.140463346189000000) * t;

    // [7,26]: 9,25,27,
    tf = CONSTANT(0.155288072035000000) * f[9] + CONSTANT(0.132882365179999990) * f[25] + CONSTANT(0.138662534056999990) * f[27];
    tg = CONSTANT(0.155288072035000000) * g[9] + CONSTANT(0.132882365179999990) * g[25] + CONSTANT(0.138662534056999990) * g[27];
    y[7] += tf * g[26] + tg * f[26];
    y[26] += tf * g[7] + tg * f[7];
    t = f[7] * g[26] + f[26] * g[7];
    y[9] += CONSTANT(0.155288072035000000) * t;
    y[25] += CONSTANT(0.132882365179999990) * t;
    y[27] += CONSTANT(0.138662534056999990) * t;

    // [7,28]: 27,11,9,29,
    tf = CONSTANT(0.114366930522000000) * f[27] + CONSTANT(0.173617342584000000) * f[11] + CONSTANT(-0.044827805096399997) * f[9] + CONSTANT(0.074118242118699995) * f[29];
    tg = CONSTANT(0.114366930522000000) * g[27] + CONSTANT(0.173617342584000000) * g[11] + CONSTANT(-0.044827805096399997) * g[9] + CONSTANT(0.074118242118699995) * g[29];
    y[7] += tf * g[28] + tg * f[28];
    y[28] += tf * g[7] + tg * f[7];
    t = f[7] * g[28] + f[28] * g[7];
    y[27] += CONSTANT(0.114366930522000000) * t;
    y[11] += CONSTANT(0.173617342584000000) * t;
    y[9] += CONSTANT(-0.044827805096399997) * t;
    y[29] += CONSTANT(0.074118242118699995) * t;

    // [7,31]: 30,12,32,
    tf = CONSTANT(0.036165998945399999) * f[30] + CONSTANT(0.214317900578999990) * f[12] + CONSTANT(0.074118242119099995) * f[32];
    tg = CONSTANT(0.036165998945399999) * g[30] + CONSTANT(0.214317900578999990) * g[12] + CONSTANT(0.074118242119099995) * g[32];
    y[7] += tf * g[31] + tg * f[31];
    y[31] += tf * g[7] + tg * f[7];
    t = f[7] * g[31] + f[31] * g[7];
    y[30] += CONSTANT(0.036165998945399999) * t;
    y[12] += CONSTANT(0.214317900578999990) * t;
    y[32] += CONSTANT(0.074118242119099995) * t;

    // [7,32]: 15,33,
    tf = CONSTANT(-0.044827805096799997) * f[15] + CONSTANT(0.114366930522000000) * f[33];
    tg = CONSTANT(-0.044827805096799997) * g[15] + CONSTANT(0.114366930522000000) * g[33];
    y[7] += tf * g[32] + tg * f[32];
    y[32] += tf * g[7] + tg * f[7];
    t = f[7] * g[32] + f[32] * g[7];
    y[15] += CONSTANT(-0.044827805096799997) * t;
    y[33] += CONSTANT(0.114366930522000000) * t;

    // [7,34]: 15,33,35,
    tf = CONSTANT(0.155288072036000010) * f[15] + CONSTANT(0.138662534059000000) * f[33] + CONSTANT(0.132882365179000010) * f[35];
    tg = CONSTANT(0.155288072036000010) * g[15] + CONSTANT(0.138662534059000000) * g[33] + CONSTANT(0.132882365179000010) * g[35];
    y[7] += tf * g[34] + tg * f[34];
    y[34] += tf * g[7] + tg * f[7];
    t = f[7] * g[34] + f[34] * g[7];
    y[15] += CONSTANT(0.155288072036000010) * t;
    y[33] += CONSTANT(0.138662534059000000) * t;
    y[35] += CONSTANT(0.132882365179000010) * t;

    // [8,8]: 0,6,20,24,
    tf = CONSTANT(0.282094791770000020) * f[0] + CONSTANT(-0.180223751576000010) * f[6] + CONSTANT(0.040299255967500003) * f[20] + CONSTANT(0.238413613505999990) * f[24];
    tg = CONSTANT(0.282094791770000020) * g[0] + CONSTANT(-0.180223751576000010) * g[6] + CONSTANT(0.040299255967500003) * g[20] + CONSTANT(0.238413613505999990) * g[24];
    y[8] += tf * g[8] + tg * f[8];
    t = f[8] * g[8];
    y[0] += CONSTANT(0.282094791770000020) * t;
    y[6] += CONSTANT(-0.180223751576000010) * t;
    y[20] += CONSTANT(0.040299255967500003) * t;
    y[24] += CONSTANT(0.238413613505999990) * t;

    // [8,9]: 1,11,25,29,
    tf = CONSTANT(0.226179013155000000) * f[1] + CONSTANT(-0.094031597259499999) * f[11] + CONSTANT(0.245532000541000000) * f[25] + CONSTANT(0.016943317729199998) * f[29];
    tg = CONSTANT(0.226179013155000000) * g[1] + CONSTANT(-0.094031597259499999) * g[11] + CONSTANT(0.245532000541000000) * g[25] + CONSTANT(0.016943317729199998) * g[29];
    y[8] += tf * g[9] + tg * f[9];
    y[9] += tf * g[8] + tg * f[8];
    t = f[8] * g[9] + f[9] * g[8];
    y[1] += CONSTANT(0.226179013155000000) * t;
    y[11] += CONSTANT(-0.094031597259499999) * t;
    y[25] += CONSTANT(0.245532000541000000) * t;
    y[29] += CONSTANT(0.016943317729199998) * t;

    // [8,14]: 2,12,30,34,
    tf = CONSTANT(0.184674390919999990) * f[2] + CONSTANT(-0.188063194517999990) * f[12] + CONSTANT(0.053579475144400000) * f[30] + CONSTANT(0.190188269816000010) * f[34];
    tg = CONSTANT(0.184674390919999990) * g[2] + CONSTANT(-0.188063194517999990) * g[12] + CONSTANT(0.053579475144400000) * g[30] + CONSTANT(0.190188269816000010) * g[34];
    y[8] += tf * g[14] + tg * f[14];
    y[14] += tf * g[8] + tg * f[8];
    t = f[8] * g[14] + f[14] * g[8];
    y[2] += CONSTANT(0.184674390919999990) * t;
    y[12] += CONSTANT(-0.188063194517999990) * t;
    y[30] += CONSTANT(0.053579475144400000) * t;
    y[34] += CONSTANT(0.190188269816000010) * t;

    // [8,15]: 13,3,31,35,
    tf = CONSTANT(-0.094031597259499999) * f[13] + CONSTANT(0.226179013155000000) * f[3] + CONSTANT(0.016943317729199998) * f[31] + CONSTANT(0.245532000541000000) * f[35];
    tg = CONSTANT(-0.094031597259499999) * g[13] + CONSTANT(0.226179013155000000) * g[3] + CONSTANT(0.016943317729199998) * g[31] + CONSTANT(0.245532000541000000) * g[35];
    y[8] += tf * g[15] + tg * f[15];
    y[15] += tf * g[8] + tg * f[8];
    t = f[8] * g[15] + f[15] * g[8];
    y[13] += CONSTANT(-0.094031597259499999) * t;
    y[3] += CONSTANT(0.226179013155000000) * t;
    y[31] += CONSTANT(0.016943317729199998) * t;
    y[35] += CONSTANT(0.245532000541000000) * t;

    // [8,22]: 6,20,24,
    tf = CONSTANT(0.156078347226000000) * f[6] + CONSTANT(-0.190364615029000010) * f[20] + CONSTANT(-0.075080816691500005) * f[24];
    tg = CONSTANT(0.156078347226000000) * g[6] + CONSTANT(-0.190364615029000010) * g[20] + CONSTANT(-0.075080816691500005) * g[24];
    y[8] += tf * g[22] + tg * f[22];
    y[22] += tf * g[8] + tg * f[8];
    t = f[8] * g[22] + f[22] * g[8];
    y[6] += CONSTANT(0.156078347226000000) * t;
    y[20] += CONSTANT(-0.190364615029000010) * t;
    y[24] += CONSTANT(-0.075080816691500005) * t;

    // [8,26]: 10,28,
    tf = CONSTANT(0.190188269806999990) * f[10] + CONSTANT(-0.097043558542400002) * f[28];
    tg = CONSTANT(0.190188269806999990) * g[10] + CONSTANT(-0.097043558542400002) * g[28];
    y[8] += tf * g[26] + tg * f[26];
    y[26] += tf * g[8] + tg * f[8];
    t = f[8] * g[26] + f[26] * g[8];
    y[10] += CONSTANT(0.190188269806999990) * t;
    y[28] += CONSTANT(-0.097043558542400002) * t;

    // [8,27]: 25,11,29,
    tf = CONSTANT(-0.062641347680800000) * f[25] + CONSTANT(0.141757966609000000) * f[11] + CONSTANT(-0.121034582550000010) * f[29];
    tg = CONSTANT(-0.062641347680800000) * g[25] + CONSTANT(0.141757966609000000) * g[11] + CONSTANT(-0.121034582550000010) * g[29];
    y[8] += tf * g[27] + tg * f[27];
    y[27] += tf * g[8] + tg * f[8];
    t = f[8] * g[27] + f[27] * g[8];
    y[25] += CONSTANT(-0.062641347680800000) * t;
    y[11] += CONSTANT(0.141757966609000000) * t;
    y[29] += CONSTANT(-0.121034582550000010) * t;

    // [8,32]: 30,12,34,
    tf = CONSTANT(-0.191372478254000000) * f[30] + CONSTANT(0.141757966609000000) * f[12] + CONSTANT(-0.097043558538899996) * f[34];
    tg = CONSTANT(-0.191372478254000000) * g[30] + CONSTANT(0.141757966609000000) * g[12] + CONSTANT(-0.097043558538899996) * g[34];
    y[8] += tf * g[32] + tg * f[32];
    y[32] += tf * g[8] + tg * f[8];
    t = f[8] * g[32] + f[32] * g[8];
    y[30] += CONSTANT(-0.191372478254000000) * t;
    y[12] += CONSTANT(0.141757966609000000) * t;
    y[34] += CONSTANT(-0.097043558538899996) * t;

    // [8,33]: 13,31,35,
    tf = CONSTANT(0.141757966609000000) * f[13] + CONSTANT(-0.121034582550000010) * f[31] + CONSTANT(-0.062641347680800000) * f[35];
    tg = CONSTANT(0.141757966609000000) * g[13] + CONSTANT(-0.121034582550000010) * g[31] + CONSTANT(-0.062641347680800000) * g[35];
    y[8] += tf * g[33] + tg * f[33];
    y[33] += tf * g[8] + tg * f[8];
    t = f[8] * g[33] + f[33] * g[8];
    y[13] += CONSTANT(0.141757966609000000) * t;
    y[31] += CONSTANT(-0.121034582550000010) * t;
    y[35] += CONSTANT(-0.062641347680800000) * t;

    // [9,9]: 6,0,20,
    tf = CONSTANT(-0.210261043508000010) * f[6] + CONSTANT(0.282094791766999970) * f[0] + CONSTANT(0.076934943209800002) * f[20];
    tg = CONSTANT(-0.210261043508000010) * g[6] + CONSTANT(0.282094791766999970) * g[0] + CONSTANT(0.076934943209800002) * g[20];
    y[9] += tf * g[9] + tg * f[9];
    t = f[9] * g[9];
    y[6] += CONSTANT(-0.210261043508000010) * t;
    y[0] += CONSTANT(0.282094791766999970) * t;
    y[20] += CONSTANT(0.076934943209800002) * t;

    // [9,17]: 2,12,30,
    tf = CONSTANT(0.162867503964999990) * f[2] + CONSTANT(-0.203550726872999990) * f[12] + CONSTANT(0.098140130728100003) * f[30];
    tg = CONSTANT(0.162867503964999990) * g[2] + CONSTANT(-0.203550726872999990) * g[12] + CONSTANT(0.098140130728100003) * g[30];
    y[9] += tf * g[17] + tg * f[17];
    y[17] += tf * g[9] + tg * f[9];
    t = f[9] * g[17] + f[17] * g[9];
    y[2] += CONSTANT(0.162867503964999990) * t;
    y[12] += CONSTANT(-0.203550726872999990) * t;
    y[30] += CONSTANT(0.098140130728100003) * t;

    // [9,18]: 3,13,31,35,
    tf = CONSTANT(-0.043528171377799997) * f[3] + CONSTANT(0.133255230519000010) * f[13] + CONSTANT(-0.101584686310000010) * f[31] + CONSTANT(0.098140130731999994) * f[35];
    tg = CONSTANT(-0.043528171377799997) * g[3] + CONSTANT(0.133255230519000010) * g[13] + CONSTANT(-0.101584686310000010) * g[31] + CONSTANT(0.098140130731999994) * g[35];
    y[9] += tf * g[18] + tg * f[18];
    y[18] += tf * g[9] + tg * f[9];
    t = f[9] * g[18] + f[18] * g[9];
    y[3] += CONSTANT(-0.043528171377799997) * t;
    y[13] += CONSTANT(0.133255230519000010) * t;
    y[31] += CONSTANT(-0.101584686310000010) * t;
    y[35] += CONSTANT(0.098140130731999994) * t;

    // [9,19]: 14,32,34,
    tf = CONSTANT(-0.099322584600699995) * f[14] + CONSTANT(0.126698363970000010) * f[32] + CONSTANT(0.131668802180999990) * f[34];
    tg = CONSTANT(-0.099322584600699995) * g[14] + CONSTANT(0.126698363970000010) * g[32] + CONSTANT(0.131668802180999990) * g[34];
    y[9] += tf * g[19] + tg * f[19];
    y[19] += tf * g[9] + tg * f[9];
    t = f[9] * g[19] + f[19] * g[9];
    y[14] += CONSTANT(-0.099322584600699995) * t;
    y[32] += CONSTANT(0.126698363970000010) * t;
    y[34] += CONSTANT(0.131668802180999990) * t;

    // [9,22]: 1,11,25,29,
    tf = CONSTANT(-0.043528171378199997) * f[1] + CONSTANT(0.133255230518000010) * f[11] + CONSTANT(-0.098140130732499997) * f[25] + CONSTANT(-0.101584686311000000) * f[29];
    tg = CONSTANT(-0.043528171378199997) * g[1] + CONSTANT(0.133255230518000010) * g[11] + CONSTANT(-0.098140130732499997) * g[25] + CONSTANT(-0.101584686311000000) * g[29];
    y[9] += tf * g[22] + tg * f[22];
    y[22] += tf * g[9] + tg * f[9];
    t = f[9] * g[22] + f[22] * g[9];
    y[1] += CONSTANT(-0.043528171378199997) * t;
    y[11] += CONSTANT(0.133255230518000010) * t;
    y[25] += CONSTANT(-0.098140130732499997) * t;
    y[29] += CONSTANT(-0.101584686311000000) * t;

    // [9,27]: 6,20,
    tf = CONSTANT(0.126792179874999990) * f[6] + CONSTANT(-0.196280261464999990) * f[20];
    tg = CONSTANT(0.126792179874999990) * g[6] + CONSTANT(-0.196280261464999990) * g[20];
    y[9] += tf * g[27] + tg * f[27];
    y[27] += tf * g[9] + tg * f[9];
    t = f[9] * g[27] + f[27] * g[9];
    y[6] += CONSTANT(0.126792179874999990) * t;
    y[20] += CONSTANT(-0.196280261464999990) * t;

    // [10,10]: 0,20,24,
    tf = CONSTANT(0.282094791771999980) * f[0] + CONSTANT(-0.179514867494000000) * f[20] + CONSTANT(-0.151717754049000010) * f[24];
    tg = CONSTANT(0.282094791771999980) * g[0] + CONSTANT(-0.179514867494000000) * g[20] + CONSTANT(-0.151717754049000010) * g[24];
    y[10] += tf * g[10] + tg * f[10];
    t = f[10] * g[10];
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[20] += CONSTANT(-0.179514867494000000) * t;
    y[24] += CONSTANT(-0.151717754049000010) * t;

    // [10,16]: 14,32,
    tf = CONSTANT(0.151717754044999990) * f[14] + CONSTANT(-0.077413979111300005) * f[32];
    tg = CONSTANT(0.151717754044999990) * g[14] + CONSTANT(-0.077413979111300005) * g[32];
    y[10] += tf * g[16] + tg * f[16];
    y[16] += tf * g[10] + tg * f[10];
    t = f[10] * g[16] + f[16] * g[10];
    y[14] += CONSTANT(0.151717754044999990) * t;
    y[32] += CONSTANT(-0.077413979111300005) * t;

    // [10,17]: 13,3,31,35,
    tf = CONSTANT(0.067850242288900006) * f[13] + CONSTANT(0.199471140200000010) * f[3] + CONSTANT(-0.113793659091000000) * f[31] + CONSTANT(-0.149911525925999990) * f[35];
    tg = CONSTANT(0.067850242288900006) * g[13] + CONSTANT(0.199471140200000010) * g[3] + CONSTANT(-0.113793659091000000) * g[31] + CONSTANT(-0.149911525925999990) * g[35];
    y[10] += tf * g[17] + tg * f[17];
    y[17] += tf * g[10] + tg * f[10];
    t = f[10] * g[17] + f[17] * g[10];
    y[13] += CONSTANT(0.067850242288900006) * t;
    y[3] += CONSTANT(0.199471140200000010) * t;
    y[31] += CONSTANT(-0.113793659091000000) * t;
    y[35] += CONSTANT(-0.149911525925999990) * t;

    // [10,18]: 12,2,30,34,
    tf = CONSTANT(-0.044418410173299998) * f[12] + CONSTANT(0.213243618621000000) * f[2] + CONSTANT(-0.171327458205000000) * f[30] + CONSTANT(-0.101358691177000000) * f[34];
    tg = CONSTANT(-0.044418410173299998) * g[12] + CONSTANT(0.213243618621000000) * g[2] + CONSTANT(-0.171327458205000000) * g[30] + CONSTANT(-0.101358691177000000) * g[34];
    y[10] += tf * g[18] + tg * f[18];
    y[18] += tf * g[10] + tg * f[10];
    t = f[10] * g[18] + f[18] * g[10];
    y[12] += CONSTANT(-0.044418410173299998) * t;
    y[2] += CONSTANT(0.213243618621000000) * t;
    y[30] += CONSTANT(-0.171327458205000000) * t;
    y[34] += CONSTANT(-0.101358691177000000) * t;

    // [10,19]: 3,15,13,31,33,
    tf = CONSTANT(-0.075393004386799994) * f[3] + CONSTANT(0.099322584599600000) * f[15] + CONSTANT(0.102579924281000000) * f[13] + CONSTANT(0.097749909976500002) * f[31] + CONSTANT(-0.025339672794100002) * f[33];
    tg = CONSTANT(-0.075393004386799994) * g[3] + CONSTANT(0.099322584599600000) * g[15] + CONSTANT(0.102579924281000000) * g[13] + CONSTANT(0.097749909976500002) * g[31] + CONSTANT(-0.025339672794100002) * g[33];
    y[10] += tf * g[19] + tg * f[19];
    y[19] += tf * g[10] + tg * f[10];
    t = f[10] * g[19] + f[19] * g[10];
    y[3] += CONSTANT(-0.075393004386799994) * t;
    y[15] += CONSTANT(0.099322584599600000) * t;
    y[13] += CONSTANT(0.102579924281000000) * t;
    y[31] += CONSTANT(0.097749909976500002) * t;
    y[33] += CONSTANT(-0.025339672794100002) * t;

    // [10,21]: 11,1,9,27,29,
    tf = CONSTANT(0.102579924281000000) * f[11] + CONSTANT(-0.075393004386799994) * f[1] + CONSTANT(-0.099322584599600000) * f[9] + CONSTANT(0.025339672794100002) * f[27] + CONSTANT(0.097749909976500002) * f[29];
    tg = CONSTANT(0.102579924281000000) * g[11] + CONSTANT(-0.075393004386799994) * g[1] + CONSTANT(-0.099322584599600000) * g[9] + CONSTANT(0.025339672794100002) * g[27] + CONSTANT(0.097749909976500002) * g[29];
    y[10] += tf * g[21] + tg * f[21];
    y[21] += tf * g[10] + tg * f[10];
    t = f[10] * g[21] + f[21] * g[10];
    y[11] += CONSTANT(0.102579924281000000) * t;
    y[1] += CONSTANT(-0.075393004386799994) * t;
    y[9] += CONSTANT(-0.099322584599600000) * t;
    y[27] += CONSTANT(0.025339672794100002) * t;
    y[29] += CONSTANT(0.097749909976500002) * t;

    // [10,23]: 11,1,25,29,
    tf = CONSTANT(-0.067850242288900006) * f[11] + CONSTANT(-0.199471140200000010) * f[1] + CONSTANT(0.149911525925999990) * f[25] + CONSTANT(0.113793659091000000) * f[29];
    tg = CONSTANT(-0.067850242288900006) * g[11] + CONSTANT(-0.199471140200000010) * g[1] + CONSTANT(0.149911525925999990) * g[25] + CONSTANT(0.113793659091000000) * g[29];
    y[10] += tf * g[23] + tg * f[23];
    y[23] += tf * g[10] + tg * f[10];
    t = f[10] * g[23] + f[23] * g[10];
    y[11] += CONSTANT(-0.067850242288900006) * t;
    y[1] += CONSTANT(-0.199471140200000010) * t;
    y[25] += CONSTANT(0.149911525925999990) * t;
    y[29] += CONSTANT(0.113793659091000000) * t;

    // [10,28]: 6,20,24,
    tf = CONSTANT(0.190188269814000000) * f[6] + CONSTANT(-0.065426753820500005) * f[20] + CONSTANT(0.077413979109600004) * f[24];
    tg = CONSTANT(0.190188269814000000) * g[6] + CONSTANT(-0.065426753820500005) * g[20] + CONSTANT(0.077413979109600004) * g[24];
    y[10] += tf * g[28] + tg * f[28];
    y[28] += tf * g[10] + tg * f[10];
    t = f[10] * g[28] + f[28] * g[10];
    y[6] += CONSTANT(0.190188269814000000) * t;
    y[20] += CONSTANT(-0.065426753820500005) * t;
    y[24] += CONSTANT(0.077413979109600004) * t;

    // [11,11]: 0,6,8,20,22,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.126156626101000010) * f[6] + CONSTANT(-0.145673124078999990) * f[8] + CONSTANT(0.025644981070299999) * f[20] + CONSTANT(-0.114687841910000000) * f[22];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.126156626101000010) * g[6] + CONSTANT(-0.145673124078999990) * g[8] + CONSTANT(0.025644981070299999) * g[20] + CONSTANT(-0.114687841910000000) * g[22];
    y[11] += tf * g[11] + tg * f[11];
    t = f[11] * g[11];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[6] += CONSTANT(0.126156626101000010) * t;
    y[8] += CONSTANT(-0.145673124078999990) * t;
    y[20] += CONSTANT(0.025644981070299999) * t;
    y[22] += CONSTANT(-0.114687841910000000) * t;

    // [11,16]: 15,33,35,
    tf = CONSTANT(-0.117520066953000000) * f[15] + CONSTANT(0.119929220739999990) * f[33] + CONSTANT(0.134084945035999990) * f[35];
    tg = CONSTANT(-0.117520066953000000) * g[15] + CONSTANT(0.119929220739999990) * g[33] + CONSTANT(0.134084945035999990) * g[35];
    y[11] += tf * g[16] + tg * f[16];
    y[16] += tf * g[11] + tg * f[11];
    t = f[11] * g[16] + f[16] * g[11];
    y[15] += CONSTANT(-0.117520066953000000) * t;
    y[33] += CONSTANT(0.119929220739999990) * t;
    y[35] += CONSTANT(0.134084945035999990) * t;

    // [11,18]: 3,13,15,31,33,
    tf = CONSTANT(0.168583882834000000) * f[3] + CONSTANT(0.114687841909000000) * f[13] + CONSTANT(-0.133255230519000010) * f[15] + CONSTANT(0.075189952564900006) * f[31] + CONSTANT(-0.101990215611000000) * f[33];
    tg = CONSTANT(0.168583882834000000) * g[3] + CONSTANT(0.114687841909000000) * g[13] + CONSTANT(-0.133255230519000010) * g[15] + CONSTANT(0.075189952564900006) * g[31] + CONSTANT(-0.101990215611000000) * g[33];
    y[11] += tf * g[18] + tg * f[18];
    y[18] += tf * g[11] + tg * f[11];
    t = f[11] * g[18] + f[18] * g[11];
    y[3] += CONSTANT(0.168583882834000000) * t;
    y[13] += CONSTANT(0.114687841909000000) * t;
    y[15] += CONSTANT(-0.133255230519000010) * t;
    y[31] += CONSTANT(0.075189952564900006) * t;
    y[33] += CONSTANT(-0.101990215611000000) * t;

    // [11,19]: 2,14,12,30,32,
    tf = CONSTANT(0.238413613504000000) * f[2] + CONSTANT(-0.102579924282000000) * f[14] + CONSTANT(0.099322584599300004) * f[12] + CONSTANT(0.009577496073830001) * f[30] + CONSTANT(-0.104682806112000000) * f[32];
    tg = CONSTANT(0.238413613504000000) * g[2] + CONSTANT(-0.102579924282000000) * g[14] + CONSTANT(0.099322584599300004) * g[12] + CONSTANT(0.009577496073830001) * g[30] + CONSTANT(-0.104682806112000000) * g[32];
    y[11] += tf * g[19] + tg * f[19];
    y[19] += tf * g[11] + tg * f[11];
    t = f[11] * g[19] + f[19] * g[11];
    y[2] += CONSTANT(0.238413613504000000) * t;
    y[14] += CONSTANT(-0.102579924282000000) * t;
    y[12] += CONSTANT(0.099322584599300004) * t;
    y[30] += CONSTANT(0.009577496073830001) * t;
    y[32] += CONSTANT(-0.104682806112000000) * t;

    // [11,24]: 9,25,27,
    tf = CONSTANT(0.117520066950999990) * f[9] + CONSTANT(-0.134084945037000000) * f[25] + CONSTANT(-0.119929220742000010) * f[27];
    tg = CONSTANT(0.117520066950999990) * g[9] + CONSTANT(-0.134084945037000000) * g[25] + CONSTANT(-0.119929220742000010) * g[27];
    y[11] += tf * g[24] + tg * f[24];
    y[24] += tf * g[11] + tg * f[11];
    t = f[11] * g[24] + f[24] * g[11];
    y[9] += CONSTANT(0.117520066950999990) * t;
    y[25] += CONSTANT(-0.134084945037000000) * t;
    y[27] += CONSTANT(-0.119929220742000010) * t;

    // [11,29]: 6,20,22,8,
    tf = CONSTANT(0.227318461243000010) * f[6] + CONSTANT(0.086019920779800002) * f[20] + CONSTANT(-0.075189952565200002) * f[22] + CONSTANT(0.065621187395299999) * f[8];
    tg = CONSTANT(0.227318461243000010) * g[6] + CONSTANT(0.086019920779800002) * g[20] + CONSTANT(-0.075189952565200002) * g[22] + CONSTANT(0.065621187395299999) * g[8];
    y[11] += tf * g[29] + tg * f[29];
    y[29] += tf * g[11] + tg * f[11];
    t = f[11] * g[29] + f[29] * g[11];
    y[6] += CONSTANT(0.227318461243000010) * t;
    y[20] += CONSTANT(0.086019920779800002) * t;
    y[22] += CONSTANT(-0.075189952565200002) * t;
    y[8] += CONSTANT(0.065621187395299999) * t;

    // [12,12]: 0,6,20,
    tf = CONSTANT(0.282094799871999980) * f[0] + CONSTANT(0.168208852954000010) * f[6] + CONSTANT(0.153869910786000010) * f[20];
    tg = CONSTANT(0.282094799871999980) * g[0] + CONSTANT(0.168208852954000010) * g[6] + CONSTANT(0.153869910786000010) * g[20];
    y[12] += tf * g[12] + tg * f[12];
    t = f[12] * g[12];
    y[0] += CONSTANT(0.282094799871999980) * t;
    y[6] += CONSTANT(0.168208852954000010) * t;
    y[20] += CONSTANT(0.153869910786000010) * t;

    // [12,30]: 20,6,
    tf = CONSTANT(0.148373961712999990) * f[20] + CONSTANT(0.239614719999000000) * f[6];
    tg = CONSTANT(0.148373961712999990) * g[20] + CONSTANT(0.239614719999000000) * g[6];
    y[12] += tf * g[30] + tg * f[30];
    y[30] += tf * g[12] + tg * f[12];
    t = f[12] * g[30] + f[30] * g[12];
    y[20] += CONSTANT(0.148373961712999990) * t;
    y[6] += CONSTANT(0.239614719999000000) * t;

    // [13,13]: 0,8,6,20,22,
    tf = CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.145673124078999990) * f[8] + CONSTANT(0.126156626101000010) * f[6] + CONSTANT(0.025644981070299999) * f[20] + CONSTANT(0.114687841910000000) * f[22];
    tg = CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.145673124078999990) * g[8] + CONSTANT(0.126156626101000010) * g[6] + CONSTANT(0.025644981070299999) * g[20] + CONSTANT(0.114687841910000000) * g[22];
    y[13] += tf * g[13] + tg * f[13];
    t = f[13] * g[13];
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[8] += CONSTANT(0.145673124078999990) * t;
    y[6] += CONSTANT(0.126156626101000010) * t;
    y[20] += CONSTANT(0.025644981070299999) * t;
    y[22] += CONSTANT(0.114687841910000000) * t;

    // [13,16]: 9,25,27,
    tf = CONSTANT(-0.117520066953000000) * f[9] + CONSTANT(-0.134084945035999990) * f[25] + CONSTANT(0.119929220739999990) * f[27];
    tg = CONSTANT(-0.117520066953000000) * g[9] + CONSTANT(-0.134084945035999990) * g[25] + CONSTANT(0.119929220739999990) * g[27];
    y[13] += tf * g[16] + tg * f[16];
    y[16] += tf * g[13] + tg * f[13];
    t = f[13] * g[16] + f[16] * g[13];
    y[9] += CONSTANT(-0.117520066953000000) * t;
    y[25] += CONSTANT(-0.134084945035999990) * t;
    y[27] += CONSTANT(0.119929220739999990) * t;

    // [13,21]: 2,12,14,30,32,
    tf = CONSTANT(0.238413613504000000) * f[2] + CONSTANT(0.099322584599300004) * f[12] + CONSTANT(0.102579924282000000) * f[14] + CONSTANT(0.009577496073830001) * f[30] + CONSTANT(0.104682806112000000) * f[32];
    tg = CONSTANT(0.238413613504000000) * g[2] + CONSTANT(0.099322584599300004) * g[12] + CONSTANT(0.102579924282000000) * g[14] + CONSTANT(0.009577496073830001) * g[30] + CONSTANT(0.104682806112000000) * g[32];
    y[13] += tf * g[21] + tg * f[21];
    y[21] += tf * g[13] + tg * f[13];
    t = f[13] * g[21] + f[21] * g[13];
    y[2] += CONSTANT(0.238413613504000000) * t;
    y[12] += CONSTANT(0.099322584599300004) * t;
    y[14] += CONSTANT(0.102579924282000000) * t;
    y[30] += CONSTANT(0.009577496073830001) * t;
    y[32] += CONSTANT(0.104682806112000000) * t;

    // [13,24]: 15,33,35,
    tf = CONSTANT(-0.117520066950999990) * f[15] + CONSTANT(0.119929220742000010) * f[33] + CONSTANT(-0.134084945037000000) * f[35];
    tg = CONSTANT(-0.117520066950999990) * g[15] + CONSTANT(0.119929220742000010) * g[33] + CONSTANT(-0.134084945037000000) * g[35];
    y[13] += tf * g[24] + tg * f[24];
    y[24] += tf * g[13] + tg * f[13];
    t = f[13] * g[24] + f[24] * g[13];
    y[15] += CONSTANT(-0.117520066950999990) * t;
    y[33] += CONSTANT(0.119929220742000010) * t;
    y[35] += CONSTANT(-0.134084945037000000) * t;

    // [13,31]: 6,22,20,8,
    tf = CONSTANT(0.227318461243000010) * f[6] + CONSTANT(0.075189952565200002) * f[22] + CONSTANT(0.086019920779800002) * f[20] + CONSTANT(-0.065621187395299999) * f[8];
    tg = CONSTANT(0.227318461243000010) * g[6] + CONSTANT(0.075189952565200002) * g[22] + CONSTANT(0.086019920779800002) * g[20] + CONSTANT(-0.065621187395299999) * g[8];
    y[13] += tf * g[31] + tg * f[31];
    y[31] += tf * g[13] + tg * f[13];
    t = f[13] * g[31] + f[31] * g[13];
    y[6] += CONSTANT(0.227318461243000010) * t;
    y[22] += CONSTANT(0.075189952565200002) * t;
    y[20] += CONSTANT(0.086019920779800002) * t;
    y[8] += CONSTANT(-0.065621187395299999) * t;

    // [14,14]: 0,20,24,
    tf = CONSTANT(0.282094791771999980) * f[0] + CONSTANT(-0.179514867494000000) * f[20] + CONSTANT(0.151717754049000010) * f[24];
    tg = CONSTANT(0.282094791771999980) * g[0] + CONSTANT(-0.179514867494000000) * g[20] + CONSTANT(0.151717754049000010) * g[24];
    y[14] += tf * g[14] + tg * f[14];
    t = f[14] * g[14];
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[20] += CONSTANT(-0.179514867494000000) * t;
    y[24] += CONSTANT(0.151717754049000010) * t;

    // [14,17]: 11,1,25,29,
    tf = CONSTANT(0.067850242288500007) * f[11] + CONSTANT(0.199471140196999990) * f[1] + CONSTANT(0.149911525925999990) * f[25] + CONSTANT(-0.113793659092000000) * f[29];
    tg = CONSTANT(0.067850242288500007) * g[11] + CONSTANT(0.199471140196999990) * g[1] + CONSTANT(0.149911525925999990) * g[25] + CONSTANT(-0.113793659092000000) * g[29];
    y[14] += tf * g[17] + tg * f[17];
    y[17] += tf * g[14] + tg * f[14];
    t = f[14] * g[17] + f[17] * g[14];
    y[11] += CONSTANT(0.067850242288500007) * t;
    y[1] += CONSTANT(0.199471140196999990) * t;
    y[25] += CONSTANT(0.149911525925999990) * t;
    y[29] += CONSTANT(-0.113793659092000000) * t;

    // [14,22]: 12,2,30,34,
    tf = CONSTANT(-0.044418410173299998) * f[12] + CONSTANT(0.213243618621000000) * f[2] + CONSTANT(-0.171327458205000000) * f[30] + CONSTANT(0.101358691177000000) * f[34];
    tg = CONSTANT(-0.044418410173299998) * g[12] + CONSTANT(0.213243618621000000) * g[2] + CONSTANT(-0.171327458205000000) * g[30] + CONSTANT(0.101358691177000000) * g[34];
    y[14] += tf * g[22] + tg * f[22];
    y[22] += tf * g[14] + tg * f[14];
    t = f[14] * g[22] + f[22] * g[14];
    y[12] += CONSTANT(-0.044418410173299998) * t;
    y[2] += CONSTANT(0.213243618621000000) * t;
    y[30] += CONSTANT(-0.171327458205000000) * t;
    y[34] += CONSTANT(0.101358691177000000) * t;

    // [14,23]: 13,3,31,35,
    tf = CONSTANT(0.067850242288500007) * f[13] + CONSTANT(0.199471140196999990) * f[3] + CONSTANT(-0.113793659092000000) * f[31] + CONSTANT(0.149911525925999990) * f[35];
    tg = CONSTANT(0.067850242288500007) * g[13] + CONSTANT(0.199471140196999990) * g[3] + CONSTANT(-0.113793659092000000) * g[31] + CONSTANT(0.149911525925999990) * g[35];
    y[14] += tf * g[23] + tg * f[23];
    y[23] += tf * g[14] + tg * f[14];
    t = f[14] * g[23] + f[23] * g[14];
    y[13] += CONSTANT(0.067850242288500007) * t;
    y[3] += CONSTANT(0.199471140196999990) * t;
    y[31] += CONSTANT(-0.113793659092000000) * t;
    y[35] += CONSTANT(0.149911525925999990) * t;

    // [14,32]: 20,6,24,
    tf = CONSTANT(-0.065426753820500005) * f[20] + CONSTANT(0.190188269814000000) * f[6] + CONSTANT(-0.077413979109600004) * f[24];
    tg = CONSTANT(-0.065426753820500005) * g[20] + CONSTANT(0.190188269814000000) * g[6] + CONSTANT(-0.077413979109600004) * g[24];
    y[14] += tf * g[32] + tg * f[32];
    y[32] += tf * g[14] + tg * f[14];
    t = f[14] * g[32] + f[32] * g[14];
    y[20] += CONSTANT(-0.065426753820500005) * t;
    y[6] += CONSTANT(0.190188269814000000) * t;
    y[24] += CONSTANT(-0.077413979109600004) * t;

    // [15,15]: 0,6,20,
    tf = CONSTANT(0.282094791766999970) * f[0] + CONSTANT(-0.210261043508000010) * f[6] + CONSTANT(0.076934943209800002) * f[20];
    tg = CONSTANT(0.282094791766999970) * g[0] + CONSTANT(-0.210261043508000010) * g[6] + CONSTANT(0.076934943209800002) * g[20];
    y[15] += tf * g[15] + tg * f[15];
    t = f[15] * g[15];
    y[0] += CONSTANT(0.282094791766999970) * t;
    y[6] += CONSTANT(-0.210261043508000010) * t;
    y[20] += CONSTANT(0.076934943209800002) * t;

    // [15,21]: 14,32,34,
    tf = CONSTANT(-0.099322584600699995) * f[14] + CONSTANT(0.126698363970000010) * f[32] + CONSTANT(-0.131668802180999990) * f[34];
    tg = CONSTANT(-0.099322584600699995) * g[14] + CONSTANT(0.126698363970000010) * g[32] + CONSTANT(-0.131668802180999990) * g[34];
    y[15] += tf * g[21] + tg * f[21];
    y[21] += tf * g[15] + tg * f[15];
    t = f[15] * g[21] + f[21] * g[15];
    y[14] += CONSTANT(-0.099322584600699995) * t;
    y[32] += CONSTANT(0.126698363970000010) * t;
    y[34] += CONSTANT(-0.131668802180999990) * t;

    // [15,22]: 13,3,31,35,
    tf = CONSTANT(0.133255230518000010) * f[13] + CONSTANT(-0.043528171378199997) * f[3] + CONSTANT(-0.101584686311000000) * f[31] + CONSTANT(-0.098140130732499997) * f[35];
    tg = CONSTANT(0.133255230518000010) * g[13] + CONSTANT(-0.043528171378199997) * g[3] + CONSTANT(-0.101584686311000000) * g[31] + CONSTANT(-0.098140130732499997) * g[35];
    y[15] += tf * g[22] + tg * f[22];
    y[22] += tf * g[15] + tg * f[15];
    t = f[15] * g[22] + f[22] * g[15];
    y[13] += CONSTANT(0.133255230518000010) * t;
    y[3] += CONSTANT(-0.043528171378199997) * t;
    y[31] += CONSTANT(-0.101584686311000000) * t;
    y[35] += CONSTANT(-0.098140130732499997) * t;

    // [15,23]: 12,2,30,
    tf = CONSTANT(-0.203550726872999990) * f[12] + CONSTANT(0.162867503964999990) * f[2] + CONSTANT(0.098140130728100003) * f[30];
    tg = CONSTANT(-0.203550726872999990) * g[12] + CONSTANT(0.162867503964999990) * g[2] + CONSTANT(0.098140130728100003) * g[30];
    y[15] += tf * g[23] + tg * f[23];
    y[23] += tf * g[15] + tg * f[15];
    t = f[15] * g[23] + f[23] * g[15];
    y[12] += CONSTANT(-0.203550726872999990) * t;
    y[2] += CONSTANT(0.162867503964999990) * t;
    y[30] += CONSTANT(0.098140130728100003) * t;

    // [15,33]: 6,20,
    tf = CONSTANT(0.126792179874999990) * f[6] + CONSTANT(-0.196280261464999990) * f[20];
    tg = CONSTANT(0.126792179874999990) * g[6] + CONSTANT(-0.196280261464999990) * g[20];
    y[15] += tf * g[33] + tg * f[33];
    y[33] += tf * g[15] + tg * f[15];
    t = f[15] * g[33] + f[33] * g[15];
    y[6] += CONSTANT(0.126792179874999990) * t;
    y[20] += CONSTANT(-0.196280261464999990) * t;

    // [16,16]: 0,6,20,
    tf = CONSTANT(0.282094791763999990) * f[0] + CONSTANT(-0.229375683829000000) * f[6] + CONSTANT(0.106525305981000000) * f[20];
    tg = CONSTANT(0.282094791763999990) * g[0] + CONSTANT(-0.229375683829000000) * g[6] + CONSTANT(0.106525305981000000) * g[20];
    y[16] += tf * g[16] + tg * f[16];
    t = f[16] * g[16];
    y[0] += CONSTANT(0.282094791763999990) * t;
    y[6] += CONSTANT(-0.229375683829000000) * t;
    y[20] += CONSTANT(0.106525305981000000) * t;

    // [16,18]: 8,22,
    tf = CONSTANT(-0.075080816693699995) * f[8] + CONSTANT(0.135045473380000000) * f[22];
    tg = CONSTANT(-0.075080816693699995) * g[8] + CONSTANT(0.135045473380000000) * g[22];
    y[16] += tf * g[18] + tg * f[18];
    y[18] += tf * g[16] + tg * f[16];
    t = f[16] * g[18] + f[18] * g[16];
    y[8] += CONSTANT(-0.075080816693699995) * t;
    y[22] += CONSTANT(0.135045473380000000) * t;

    // [16,23]: 19,5,
    tf = CONSTANT(-0.119098912754999990) * f[19] + CONSTANT(0.140463346187999990) * f[5];
    tg = CONSTANT(-0.119098912754999990) * g[19] + CONSTANT(0.140463346187999990) * g[5];
    y[16] += tf * g[23] + tg * f[23];
    y[23] += tf * g[16] + tg * f[16];
    t = f[16] * g[23] + f[23] * g[16];
    y[19] += CONSTANT(-0.119098912754999990) * t;
    y[5] += CONSTANT(0.140463346187999990) * t;

    // [16,26]: 12,2,30,
    tf = CONSTANT(-0.207723503645000000) * f[12] + CONSTANT(0.147319200325000010) * f[2] + CONSTANT(0.130197596199999990) * f[30];
    tg = CONSTANT(-0.207723503645000000) * g[12] + CONSTANT(0.147319200325000010) * g[2] + CONSTANT(0.130197596199999990) * g[30];
    y[16] += tf * g[26] + tg * f[26];
    y[26] += tf * g[16] + tg * f[16];
    t = f[16] * g[26] + f[26] * g[16];
    y[12] += CONSTANT(-0.207723503645000000) * t;
    y[2] += CONSTANT(0.147319200325000010) * t;
    y[30] += CONSTANT(0.130197596199999990) * t;

    // [16,28]: 14,32,
    tf = CONSTANT(-0.077413979111300005) * f[14] + CONSTANT(0.128376561115000010) * f[32];
    tg = CONSTANT(-0.077413979111300005) * g[14] + CONSTANT(0.128376561115000010) * g[32];
    y[16] += tf * g[28] + tg * f[28];
    y[28] += tf * g[16] + tg * f[16];
    t = f[16] * g[28] + f[28] * g[16];
    y[14] += CONSTANT(-0.077413979111300005) * t;
    y[32] += CONSTANT(0.128376561115000010) * t;

    // [16,29]: 15,33,35,
    tf = CONSTANT(0.035835708931099997) * f[15] + CONSTANT(-0.118853600623999990) * f[33] + CONSTANT(-0.053152946071899999) * f[35];
    tg = CONSTANT(0.035835708931099997) * g[15] + CONSTANT(-0.118853600623999990) * g[33] + CONSTANT(-0.053152946071899999) * g[35];
    y[16] += tf * g[29] + tg * f[29];
    y[29] += tf * g[16] + tg * f[16];
    t = f[16] * g[29] + f[29] * g[16];
    y[15] += CONSTANT(0.035835708931099997) * t;
    y[33] += CONSTANT(-0.118853600623999990) * t;
    y[35] += CONSTANT(-0.053152946071899999) * t;

    // [16,31]: 27,9,25,
    tf = CONSTANT(-0.118853600623999990) * f[27] + CONSTANT(0.035835708931099997) * f[9] + CONSTANT(0.053152946071899999) * f[25];
    tg = CONSTANT(-0.118853600623999990) * g[27] + CONSTANT(0.035835708931099997) * g[9] + CONSTANT(0.053152946071899999) * g[25];
    y[16] += tf * g[31] + tg * f[31];
    y[31] += tf * g[16] + tg * f[16];
    t = f[16] * g[31] + f[31] * g[16];
    y[27] += CONSTANT(-0.118853600623999990) * t;
    y[9] += CONSTANT(0.035835708931099997) * t;
    y[25] += CONSTANT(0.053152946071899999) * t;

    // [17,17]: 0,6,20,
    tf = CONSTANT(0.282094791768999990) * f[0] + CONSTANT(-0.057343920955899998) * f[6] + CONSTANT(-0.159787958979000000) * f[20];
    tg = CONSTANT(0.282094791768999990) * g[0] + CONSTANT(-0.057343920955899998) * g[6] + CONSTANT(-0.159787958979000000) * g[20];
    y[17] += tf * g[17] + tg * f[17];
    t = f[17] * g[17];
    y[0] += CONSTANT(0.282094791768999990) * t;
    y[6] += CONSTANT(-0.057343920955899998) * t;
    y[20] += CONSTANT(-0.159787958979000000) * t;

    // [17,19]: 8,22,24,
    tf = CONSTANT(-0.112621225039000000) * f[8] + CONSTANT(0.045015157794100001) * f[22] + CONSTANT(0.119098912753000000) * f[24];
    tg = CONSTANT(-0.112621225039000000) * g[8] + CONSTANT(0.045015157794100001) * g[22] + CONSTANT(0.119098912753000000) * g[24];
    y[17] += tf * g[19] + tg * f[19];
    y[19] += tf * g[17] + tg * f[17];
    t = f[17] * g[19] + f[19] * g[17];
    y[8] += CONSTANT(-0.112621225039000000) * t;
    y[22] += CONSTANT(0.045015157794100001) * t;
    y[24] += CONSTANT(0.119098912753000000) * t;

    // [17,21]: 16,4,18,
    tf = CONSTANT(-0.119098912754999990) * f[16] + CONSTANT(-0.112621225039000000) * f[4] + CONSTANT(0.045015157794399997) * f[18];
    tg = CONSTANT(-0.119098912754999990) * g[16] + CONSTANT(-0.112621225039000000) * g[4] + CONSTANT(0.045015157794399997) * g[18];
    y[17] += tf * g[21] + tg * f[21];
    y[21] += tf * g[17] + tg * f[17];
    t = f[17] * g[21] + f[21] * g[17];
    y[16] += CONSTANT(-0.119098912754999990) * t;
    y[4] += CONSTANT(-0.112621225039000000) * t;
    y[18] += CONSTANT(0.045015157794399997) * t;

    // [17,26]: 3,13,31,
    tf = CONSTANT(0.208340811096000000) * f[3] + CONSTANT(0.029982305185199998) * f[13] + CONSTANT(-0.118853600623999990) * f[31];
    tg = CONSTANT(0.208340811096000000) * g[3] + CONSTANT(0.029982305185199998) * g[13] + CONSTANT(-0.118853600623999990) * g[31];
    y[17] += tf * g[26] + tg * f[26];
    y[26] += tf * g[17] + tg * f[17];
    t = f[17] * g[26] + f[26] * g[17];
    y[3] += CONSTANT(0.208340811096000000) * t;
    y[13] += CONSTANT(0.029982305185199998) * t;
    y[31] += CONSTANT(-0.118853600623999990) * t;

    // [17,27]: 12,2,30,
    tf = CONSTANT(-0.103861751821000010) * f[12] + CONSTANT(0.196425600433000000) * f[2] + CONSTANT(-0.130197596204999990) * f[30];
    tg = CONSTANT(-0.103861751821000010) * g[12] + CONSTANT(0.196425600433000000) * g[2] + CONSTANT(-0.130197596204999990) * g[30];
    y[17] += tf * g[27] + tg * f[27];
    y[27] += tf * g[17] + tg * f[17];
    t = f[17] * g[27] + f[27] * g[17];
    y[12] += CONSTANT(-0.103861751821000010) * t;
    y[2] += CONSTANT(0.196425600433000000) * t;
    y[30] += CONSTANT(-0.130197596204999990) * t;

    // [17,28]: 13,3,31,35,
    tf = CONSTANT(0.121172043789000000) * f[13] + CONSTANT(-0.060142811686500000) * f[3] + CONSTANT(0.034310079156700000) * f[31] + CONSTANT(0.099440056652200001) * f[35];
    tg = CONSTANT(0.121172043789000000) * g[13] + CONSTANT(-0.060142811686500000) * g[3] + CONSTANT(0.034310079156700000) * g[31] + CONSTANT(0.099440056652200001) * g[35];
    y[17] += tf * g[28] + tg * f[28];
    y[28] += tf * g[17] + tg * f[17];
    t = f[17] * g[28] + f[28] * g[17];
    y[13] += CONSTANT(0.121172043789000000) * t;
    y[3] += CONSTANT(-0.060142811686500000) * t;
    y[31] += CONSTANT(0.034310079156700000) * t;
    y[35] += CONSTANT(0.099440056652200001) * t;

    // [17,32]: 11,1,25,29,
    tf = CONSTANT(0.121172043788000010) * f[11] + CONSTANT(-0.060142811686900000) * f[1] + CONSTANT(-0.099440056652700004) * f[25] + CONSTANT(0.034310079156599997) * f[29];
    tg = CONSTANT(0.121172043788000010) * g[11] + CONSTANT(-0.060142811686900000) * g[1] + CONSTANT(-0.099440056652700004) * g[25] + CONSTANT(0.034310079156599997) * g[29];
    y[17] += tf * g[32] + tg * f[32];
    y[32] += tf * g[17] + tg * f[17];
    t = f[17] * g[32] + f[32] * g[17];
    y[11] += CONSTANT(0.121172043788000010) * t;
    y[1] += CONSTANT(-0.060142811686900000) * t;
    y[25] += CONSTANT(-0.099440056652700004) * t;
    y[29] += CONSTANT(0.034310079156599997) * t;

    // [17,34]: 29,11,1,
    tf = CONSTANT(0.118853600623000000) * f[29] + CONSTANT(-0.029982305185400002) * f[11] + CONSTANT(-0.208340811100000000) * f[1];
    tg = CONSTANT(0.118853600623000000) * g[29] + CONSTANT(-0.029982305185400002) * g[11] + CONSTANT(-0.208340811100000000) * g[1];
    y[17] += tf * g[34] + tg * f[34];
    y[34] += tf * g[17] + tg * f[17];
    t = f[17] * g[34] + f[34] * g[17];
    y[29] += CONSTANT(0.118853600623000000) * t;
    y[11] += CONSTANT(-0.029982305185400002) * t;
    y[1] += CONSTANT(-0.208340811100000000) * t;

    // [18,18]: 6,0,20,24,
    tf = CONSTANT(0.065535909662600006) * f[6] + CONSTANT(0.282094791771999980) * f[0] + CONSTANT(-0.083698454702400005) * f[20] + CONSTANT(-0.135045473384000000) * f[24];
    tg = CONSTANT(0.065535909662600006) * g[6] + CONSTANT(0.282094791771999980) * g[0] + CONSTANT(-0.083698454702400005) * g[20] + CONSTANT(-0.135045473384000000) * g[24];
    y[18] += tf * g[18] + tg * f[18];
    t = f[18] * g[18];
    y[6] += CONSTANT(0.065535909662600006) * t;
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[20] += CONSTANT(-0.083698454702400005) * t;
    y[24] += CONSTANT(-0.135045473384000000) * t;

    // [18,19]: 7,21,23,
    tf = CONSTANT(0.090297865407399994) * f[7] + CONSTANT(0.102084782359000000) * f[21] + CONSTANT(-0.045015157794399997) * f[23];
    tg = CONSTANT(0.090297865407399994) * g[7] + CONSTANT(0.102084782359000000) * g[21] + CONSTANT(-0.045015157794399997) * g[23];
    y[18] += tf * g[19] + tg * f[19];
    y[19] += tf * g[18] + tg * f[18];
    t = f[18] * g[19] + f[19] * g[18];
    y[7] += CONSTANT(0.090297865407399994) * t;
    y[21] += CONSTANT(0.102084782359000000) * t;
    y[23] += CONSTANT(-0.045015157794399997) * t;

    // [18,25]: 15,33,
    tf = CONSTANT(-0.098140130731999994) * f[15] + CONSTANT(0.130197596202000000) * f[33];
    tg = CONSTANT(-0.098140130731999994) * g[15] + CONSTANT(0.130197596202000000) * g[33];
    y[18] += tf * g[25] + tg * f[25];
    y[25] += tf * g[18] + tg * f[18];
    t = f[18] * g[25] + f[25] * g[18];
    y[15] += CONSTANT(-0.098140130731999994) * t;
    y[33] += CONSTANT(0.130197596202000000) * t;

    // [18,26]: 14,32,
    tf = CONSTANT(0.101358691174000000) * f[14] + CONSTANT(0.084042186965900004) * f[32];
    tg = CONSTANT(0.101358691174000000) * g[14] + CONSTANT(0.084042186965900004) * g[32];
    y[18] += tf * g[26] + tg * f[26];
    y[26] += tf * g[18] + tg * f[18];
    t = f[18] * g[26] + f[26] * g[18];
    y[14] += CONSTANT(0.101358691174000000) * t;
    y[32] += CONSTANT(0.084042186965900004) * t;

    // [18,27]: 13,3,35,
    tf = CONSTANT(0.101990215611000000) * f[13] + CONSTANT(0.183739324705999990) * f[3] + CONSTANT(-0.130197596202000000) * f[35];
    tg = CONSTANT(0.101990215611000000) * g[13] + CONSTANT(0.183739324705999990) * g[3] + CONSTANT(-0.130197596202000000) * g[35];
    y[18] += tf * g[27] + tg * f[27];
    y[27] += tf * g[18] + tg * f[18];
    t = f[18] * g[27] + f[27] * g[18];
    y[13] += CONSTANT(0.101990215611000000) * t;
    y[3] += CONSTANT(0.183739324705999990) * t;
    y[35] += CONSTANT(-0.130197596202000000) * t;

    // [18,28]: 2,12,30,34,
    tf = CONSTANT(0.225033795606000010) * f[2] + CONSTANT(0.022664492358099999) * f[12] + CONSTANT(-0.099440056651100006) * f[30] + CONSTANT(-0.084042186968800003) * f[34];
    tg = CONSTANT(0.225033795606000010) * g[2] + CONSTANT(0.022664492358099999) * g[12] + CONSTANT(-0.099440056651100006) * g[30] + CONSTANT(-0.084042186968800003) * g[34];
    y[18] += tf * g[28] + tg * f[28];
    y[28] += tf * g[18] + tg * f[18];
    t = f[18] * g[28] + f[28] * g[18];
    y[2] += CONSTANT(0.225033795606000010) * t;
    y[12] += CONSTANT(0.022664492358099999) * t;
    y[30] += CONSTANT(-0.099440056651100006) * t;
    y[34] += CONSTANT(-0.084042186968800003) * t;

    // [18,29]: 3,13,15,31,
    tf = CONSTANT(-0.085054779966799998) * f[3] + CONSTANT(0.075189952564900006) * f[13] + CONSTANT(0.101584686310000010) * f[15] + CONSTANT(0.097043558538999999) * f[31];
    tg = CONSTANT(-0.085054779966799998) * g[3] + CONSTANT(0.075189952564900006) * g[13] + CONSTANT(0.101584686310000010) * g[15] + CONSTANT(0.097043558538999999) * g[31];
    y[18] += tf * g[29] + tg * f[29];
    y[29] += tf * g[18] + tg * f[18];
    t = f[18] * g[29] + f[29] * g[18];
    y[3] += CONSTANT(-0.085054779966799998) * t;
    y[13] += CONSTANT(0.075189952564900006) * t;
    y[15] += CONSTANT(0.101584686310000010) * t;
    y[31] += CONSTANT(0.097043558538999999) * t;

    // [19,19]: 6,8,0,20,22,
    tf = CONSTANT(0.139263808033999990) * f[6] + CONSTANT(-0.141889406570999990) * f[8] + CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.068480553847200004) * f[20] + CONSTANT(-0.102084782360000000) * f[22];
    tg = CONSTANT(0.139263808033999990) * g[6] + CONSTANT(-0.141889406570999990) * g[8] + CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.068480553847200004) * g[20] + CONSTANT(-0.102084782360000000) * g[22];
    y[19] += tf * g[19] + tg * f[19];
    t = f[19] * g[19];
    y[6] += CONSTANT(0.139263808033999990) * t;
    y[8] += CONSTANT(-0.141889406570999990) * t;
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[20] += CONSTANT(0.068480553847200004) * t;
    y[22] += CONSTANT(-0.102084782360000000) * t;

    // [19,25]: 34,
    tf = CONSTANT(-0.130197596205999990) * f[34];
    tg = CONSTANT(-0.130197596205999990) * g[34];
    y[19] += tf * g[25] + tg * f[25];
    y[25] += tf * g[19] + tg * f[19];
    t = f[19] * g[25] + f[25] * g[19];
    y[34] += CONSTANT(-0.130197596205999990) * t;

    // [19,26]: 15,35,
    tf = CONSTANT(-0.131668802182000000) * f[15] + CONSTANT(0.130197596204999990) * f[35];
    tg = CONSTANT(-0.131668802182000000) * g[15] + CONSTANT(0.130197596204999990) * g[35];
    y[19] += tf * g[26] + tg * f[26];
    y[26] += tf * g[19] + tg * f[19];
    t = f[19] * g[26] + f[26] * g[19];
    y[15] += CONSTANT(-0.131668802182000000) * t;
    y[35] += CONSTANT(0.130197596204999990) * t;

    // [19,27]: 14,32,
    tf = CONSTANT(0.025339672793899998) * f[14] + CONSTANT(0.084042186967699994) * f[32];
    tg = CONSTANT(0.025339672793899998) * g[14] + CONSTANT(0.084042186967699994) * g[32];
    y[19] += tf * g[27] + tg * f[27];
    y[27] += tf * g[19] + tg * f[19];
    t = f[19] * g[27] + f[27] * g[19];
    y[14] += CONSTANT(0.025339672793899998) * t;
    y[32] += CONSTANT(0.084042186967699994) * t;

    // [19,28]: 13,3,15,31,33,
    tf = CONSTANT(0.104682806111000000) * f[13] + CONSTANT(0.159122922869999990) * f[3] + CONSTANT(-0.126698363970000010) * f[15] + CONSTANT(0.090775936911399999) * f[31] + CONSTANT(-0.084042186968400004) * f[33];
    tg = CONSTANT(0.104682806111000000) * g[13] + CONSTANT(0.159122922869999990) * g[3] + CONSTANT(-0.126698363970000010) * g[15] + CONSTANT(0.090775936911399999) * g[31] + CONSTANT(-0.084042186968400004) * g[33];
    y[19] += tf * g[28] + tg * f[28];
    y[28] += tf * g[19] + tg * f[19];
    t = f[19] * g[28] + f[28] * g[19];
    y[13] += CONSTANT(0.104682806111000000) * t;
    y[3] += CONSTANT(0.159122922869999990) * t;
    y[15] += CONSTANT(-0.126698363970000010) * t;
    y[31] += CONSTANT(0.090775936911399999) * t;
    y[33] += CONSTANT(-0.084042186968400004) * t;

    // [19,29]: 12,14,2,30,32,
    tf = CONSTANT(0.115089467124000010) * f[12] + CONSTANT(-0.097749909977199997) * f[14] + CONSTANT(0.240571246744999990) * f[2] + CONSTANT(0.053152946072499999) * f[30] + CONSTANT(-0.090775936912099994) * f[32];
    tg = CONSTANT(0.115089467124000010) * g[12] + CONSTANT(-0.097749909977199997) * g[14] + CONSTANT(0.240571246744999990) * g[2] + CONSTANT(0.053152946072499999) * g[30] + CONSTANT(-0.090775936912099994) * g[32];
    y[19] += tf * g[29] + tg * f[29];
    y[29] += tf * g[19] + tg * f[19];
    t = f[19] * g[29] + f[29] * g[19];
    y[12] += CONSTANT(0.115089467124000010) * t;
    y[14] += CONSTANT(-0.097749909977199997) * t;
    y[2] += CONSTANT(0.240571246744999990) * t;
    y[30] += CONSTANT(0.053152946072499999) * t;
    y[32] += CONSTANT(-0.090775936912099994) * t;

    // [20,20]: 6,0,20,
    tf = CONSTANT(0.163839797503000010) * f[6] + CONSTANT(0.282094802232000010) * f[0];
    tg = CONSTANT(0.163839797503000010) * g[6] + CONSTANT(0.282094802232000010) * g[0];
    y[20] += tf * g[20] + tg * f[20];
    t = f[20] * g[20];
    y[6] += CONSTANT(0.163839797503000010) * t;
    y[0] += CONSTANT(0.282094802232000010) * t;
    y[20] += CONSTANT(0.136961139005999990) * t;

    // [21,21]: 6,20,0,8,22,
    tf = CONSTANT(0.139263808033999990) * f[6] + CONSTANT(0.068480553847200004) * f[20] + CONSTANT(0.282094791773999990) * f[0] + CONSTANT(0.141889406570999990) * f[8] + CONSTANT(0.102084782360000000) * f[22];
    tg = CONSTANT(0.139263808033999990) * g[6] + CONSTANT(0.068480553847200004) * g[20] + CONSTANT(0.282094791773999990) * g[0] + CONSTANT(0.141889406570999990) * g[8] + CONSTANT(0.102084782360000000) * g[22];
    y[21] += tf * g[21] + tg * f[21];
    t = f[21] * g[21];
    y[6] += CONSTANT(0.139263808033999990) * t;
    y[20] += CONSTANT(0.068480553847200004) * t;
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[8] += CONSTANT(0.141889406570999990) * t;
    y[22] += CONSTANT(0.102084782360000000) * t;

    // [21,23]: 8,22,24,
    tf = CONSTANT(-0.112621225039000000) * f[8] + CONSTANT(0.045015157794100001) * f[22] + CONSTANT(-0.119098912753000000) * f[24];
    tg = CONSTANT(-0.112621225039000000) * g[8] + CONSTANT(0.045015157794100001) * g[22] + CONSTANT(-0.119098912753000000) * g[24];
    y[21] += tf * g[23] + tg * f[23];
    y[23] += tf * g[21] + tg * f[21];
    t = f[21] * g[23] + f[23] * g[21];
    y[8] += CONSTANT(-0.112621225039000000) * t;
    y[22] += CONSTANT(0.045015157794100001) * t;
    y[24] += CONSTANT(-0.119098912753000000) * t;

    // [21,26]: 9,25,
    tf = CONSTANT(-0.131668802182000000) * f[9] + CONSTANT(-0.130197596204999990) * f[25];
    tg = CONSTANT(-0.131668802182000000) * g[9] + CONSTANT(-0.130197596204999990) * g[25];
    y[21] += tf * g[26] + tg * f[26];
    y[26] += tf * g[21] + tg * f[21];
    t = f[21] * g[26] + f[26] * g[21];
    y[9] += CONSTANT(-0.131668802182000000) * t;
    y[25] += CONSTANT(-0.130197596204999990) * t;

    // [21,28]: 27,1,11,9,29,
    tf = CONSTANT(0.084042186968400004) * f[27] + CONSTANT(0.159122922869999990) * f[1] + CONSTANT(0.104682806111000000) * f[11] + CONSTANT(0.126698363970000010) * f[9] + CONSTANT(0.090775936911399999) * f[29];
    tg = CONSTANT(0.084042186968400004) * g[27] + CONSTANT(0.159122922869999990) * g[1] + CONSTANT(0.104682806111000000) * g[11] + CONSTANT(0.126698363970000010) * g[9] + CONSTANT(0.090775936911399999) * g[29];
    y[21] += tf * g[28] + tg * f[28];
    y[28] += tf * g[21] + tg * f[21];
    t = f[21] * g[28] + f[28] * g[21];
    y[27] += CONSTANT(0.084042186968400004) * t;
    y[1] += CONSTANT(0.159122922869999990) * t;
    y[11] += CONSTANT(0.104682806111000000) * t;
    y[9] += CONSTANT(0.126698363970000010) * t;
    y[29] += CONSTANT(0.090775936911399999) * t;

    // [21,31]: 14,2,30,12,32,
    tf = CONSTANT(0.097749909977199997) * f[14] + CONSTANT(0.240571246744999990) * f[2] + CONSTANT(0.053152946072499999) * f[30] + CONSTANT(0.115089467124000010) * f[12] + CONSTANT(0.090775936912099994) * f[32];
    tg = CONSTANT(0.097749909977199997) * g[14] + CONSTANT(0.240571246744999990) * g[2] + CONSTANT(0.053152946072499999) * g[30] + CONSTANT(0.115089467124000010) * g[12] + CONSTANT(0.090775936912099994) * g[32];
    y[21] += tf * g[31] + tg * f[31];
    y[31] += tf * g[21] + tg * f[21];
    t = f[21] * g[31] + f[31] * g[21];
    y[14] += CONSTANT(0.097749909977199997) * t;
    y[2] += CONSTANT(0.240571246744999990) * t;
    y[30] += CONSTANT(0.053152946072499999) * t;
    y[12] += CONSTANT(0.115089467124000010) * t;
    y[32] += CONSTANT(0.090775936912099994) * t;

    // [21,33]: 32,14,
    tf = CONSTANT(0.084042186967699994) * f[32] + CONSTANT(0.025339672793899998) * f[14];
    tg = CONSTANT(0.084042186967699994) * g[32] + CONSTANT(0.025339672793899998) * g[14];
    y[21] += tf * g[33] + tg * f[33];
    y[33] += tf * g[21] + tg * f[21];
    t = f[21] * g[33] + f[33] * g[21];
    y[32] += CONSTANT(0.084042186967699994) * t;
    y[14] += CONSTANT(0.025339672793899998) * t;

    // [21,34]: 35,
    tf = CONSTANT(-0.130197596205999990) * f[35];
    tg = CONSTANT(-0.130197596205999990) * g[35];
    y[21] += tf * g[34] + tg * f[34];
    y[34] += tf * g[21] + tg * f[21];
    t = f[21] * g[34] + f[34] * g[21];
    y[35] += CONSTANT(-0.130197596205999990) * t;

    // [22,22]: 6,20,0,24,
    tf = CONSTANT(0.065535909662600006) * f[6] + CONSTANT(-0.083698454702400005) * f[20] + CONSTANT(0.282094791771999980) * f[0] + CONSTANT(0.135045473384000000) * f[24];
    tg = CONSTANT(0.065535909662600006) * g[6] + CONSTANT(-0.083698454702400005) * g[20] + CONSTANT(0.282094791771999980) * g[0] + CONSTANT(0.135045473384000000) * g[24];
    y[22] += tf * g[22] + tg * f[22];
    t = f[22] * g[22];
    y[6] += CONSTANT(0.065535909662600006) * t;
    y[20] += CONSTANT(-0.083698454702400005) * t;
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[24] += CONSTANT(0.135045473384000000) * t;

    // [22,26]: 10,28,
    tf = CONSTANT(0.101358691174000000) * f[10] + CONSTANT(0.084042186965900004) * f[28];
    tg = CONSTANT(0.101358691174000000) * g[10] + CONSTANT(0.084042186965900004) * g[28];
    y[22] += tf * g[26] + tg * f[26];
    y[26] += tf * g[22] + tg * f[22];
    t = f[22] * g[26] + f[26] * g[22];
    y[10] += CONSTANT(0.101358691174000000) * t;
    y[28] += CONSTANT(0.084042186965900004) * t;

    // [22,27]: 1,11,25,
    tf = CONSTANT(0.183739324704000010) * f[1] + CONSTANT(0.101990215611000000) * f[11] + CONSTANT(0.130197596200999990) * f[25];
    tg = CONSTANT(0.183739324704000010) * g[1] + CONSTANT(0.101990215611000000) * g[11] + CONSTANT(0.130197596200999990) * g[25];
    y[22] += tf * g[27] + tg * f[27];
    y[27] += tf * g[22] + tg * f[22];
    t = f[22] * g[27] + f[27] * g[22];
    y[1] += CONSTANT(0.183739324704000010) * t;
    y[11] += CONSTANT(0.101990215611000000) * t;
    y[25] += CONSTANT(0.130197596200999990) * t;

    // [22,32]: 2,30,12,34,
    tf = CONSTANT(0.225033795606000010) * f[2] + CONSTANT(-0.099440056651100006) * f[30] + CONSTANT(0.022664492358099999) * f[12] + CONSTANT(0.084042186968800003) * f[34];
    tg = CONSTANT(0.225033795606000010) * g[2] + CONSTANT(-0.099440056651100006) * g[30] + CONSTANT(0.022664492358099999) * g[12] + CONSTANT(0.084042186968800003) * g[34];
    y[22] += tf * g[32] + tg * f[32];
    y[32] += tf * g[22] + tg * f[22];
    t = f[22] * g[32] + f[32] * g[22];
    y[2] += CONSTANT(0.225033795606000010) * t;
    y[30] += CONSTANT(-0.099440056651100006) * t;
    y[12] += CONSTANT(0.022664492358099999) * t;
    y[34] += CONSTANT(0.084042186968800003) * t;

    // [22,33]: 3,13,35,
    tf = CONSTANT(0.183739324704000010) * f[3] + CONSTANT(0.101990215611000000) * f[13] + CONSTANT(0.130197596200999990) * f[35];
    tg = CONSTANT(0.183739324704000010) * g[3] + CONSTANT(0.101990215611000000) * g[13] + CONSTANT(0.130197596200999990) * g[35];
    y[22] += tf * g[33] + tg * f[33];
    y[33] += tf * g[22] + tg * f[22];
    t = f[22] * g[33] + f[33] * g[22];
    y[3] += CONSTANT(0.183739324704000010) * t;
    y[13] += CONSTANT(0.101990215611000000) * t;
    y[35] += CONSTANT(0.130197596200999990) * t;

    // [23,23]: 6,20,0,
    tf = CONSTANT(-0.057343920955899998) * f[6] + CONSTANT(-0.159787958979000000) * f[20] + CONSTANT(0.282094791768999990) * f[0];
    tg = CONSTANT(-0.057343920955899998) * g[6] + CONSTANT(-0.159787958979000000) * g[20] + CONSTANT(0.282094791768999990) * g[0];
    y[23] += tf * g[23] + tg * f[23];
    t = f[23] * g[23];
    y[6] += CONSTANT(-0.057343920955899998) * t;
    y[20] += CONSTANT(-0.159787958979000000) * t;
    y[0] += CONSTANT(0.282094791768999990) * t;

    // [23,26]: 1,11,29,
    tf = CONSTANT(0.208340811096000000) * f[1] + CONSTANT(0.029982305185199998) * f[11] + CONSTANT(-0.118853600623999990) * f[29];
    tg = CONSTANT(0.208340811096000000) * g[1] + CONSTANT(0.029982305185199998) * g[11] + CONSTANT(-0.118853600623999990) * g[29];
    y[23] += tf * g[26] + tg * f[26];
    y[26] += tf * g[23] + tg * f[23];
    t = f[23] * g[26] + f[26] * g[23];
    y[1] += CONSTANT(0.208340811096000000) * t;
    y[11] += CONSTANT(0.029982305185199998) * t;
    y[29] += CONSTANT(-0.118853600623999990) * t;

    // [23,28]: 25,11,1,29,
    tf = CONSTANT(-0.099440056652200001) * f[25] + CONSTANT(-0.121172043789000000) * f[11] + CONSTANT(0.060142811686500000) * f[1] + CONSTANT(-0.034310079156700000) * f[29];
    tg = CONSTANT(-0.099440056652200001) * g[25] + CONSTANT(-0.121172043789000000) * g[11] + CONSTANT(0.060142811686500000) * g[1] + CONSTANT(-0.034310079156700000) * g[29];
    y[23] += tf * g[28] + tg * f[28];
    y[28] += tf * g[23] + tg * f[23];
    t = f[23] * g[28] + f[28] * g[23];
    y[25] += CONSTANT(-0.099440056652200001) * t;
    y[11] += CONSTANT(-0.121172043789000000) * t;
    y[1] += CONSTANT(0.060142811686500000) * t;
    y[29] += CONSTANT(-0.034310079156700000) * t;

    // [23,32]: 31,13,3,35,
    tf = CONSTANT(0.034310079156599997) * f[31] + CONSTANT(0.121172043788000010) * f[13] + CONSTANT(-0.060142811686900000) * f[3] + CONSTANT(-0.099440056652700004) * f[35];
    tg = CONSTANT(0.034310079156599997) * g[31] + CONSTANT(0.121172043788000010) * g[13] + CONSTANT(-0.060142811686900000) * g[3] + CONSTANT(-0.099440056652700004) * g[35];
    y[23] += tf * g[32] + tg * f[32];
    y[32] += tf * g[23] + tg * f[23];
    t = f[23] * g[32] + f[32] * g[23];
    y[31] += CONSTANT(0.034310079156599997) * t;
    y[13] += CONSTANT(0.121172043788000010) * t;
    y[3] += CONSTANT(-0.060142811686900000) * t;
    y[35] += CONSTANT(-0.099440056652700004) * t;

    // [23,33]: 2,30,12,
    tf = CONSTANT(0.196425600433000000) * f[2] + CONSTANT(-0.130197596204999990) * f[30] + CONSTANT(-0.103861751821000010) * f[12];
    tg = CONSTANT(0.196425600433000000) * g[2] + CONSTANT(-0.130197596204999990) * g[30] + CONSTANT(-0.103861751821000010) * g[12];
    y[23] += tf * g[33] + tg * f[33];
    y[33] += tf * g[23] + tg * f[23];
    t = f[23] * g[33] + f[33] * g[23];
    y[2] += CONSTANT(0.196425600433000000) * t;
    y[30] += CONSTANT(-0.130197596204999990) * t;
    y[12] += CONSTANT(-0.103861751821000010) * t;

    // [23,34]: 3,13,31,
    tf = CONSTANT(0.208340811100000000) * f[3] + CONSTANT(0.029982305185400002) * f[13] + CONSTANT(-0.118853600623000000) * f[31];
    tg = CONSTANT(0.208340811100000000) * g[3] + CONSTANT(0.029982305185400002) * g[13] + CONSTANT(-0.118853600623000000) * g[31];
    y[23] += tf * g[34] + tg * f[34];
    y[34] += tf * g[23] + tg * f[23];
    t = f[23] * g[34] + f[34] * g[23];
    y[3] += CONSTANT(0.208340811100000000) * t;
    y[13] += CONSTANT(0.029982305185400002) * t;
    y[31] += CONSTANT(-0.118853600623000000) * t;

    // [24,24]: 6,0,20,
    tf = CONSTANT(-0.229375683829000000) * f[6] + CONSTANT(0.282094791763999990) * f[0] + CONSTANT(0.106525305981000000) * f[20];
    tg = CONSTANT(-0.229375683829000000) * g[6] + CONSTANT(0.282094791763999990) * g[0] + CONSTANT(0.106525305981000000) * g[20];
    y[24] += tf * g[24] + tg * f[24];
    t = f[24] * g[24];
    y[6] += CONSTANT(-0.229375683829000000) * t;
    y[0] += CONSTANT(0.282094791763999990) * t;
    y[20] += CONSTANT(0.106525305981000000) * t;

    // [24,29]: 9,27,25,
    tf = CONSTANT(-0.035835708931400000) * f[9] + CONSTANT(0.118853600623000000) * f[27] + CONSTANT(0.053152946071199997) * f[25];
    tg = CONSTANT(-0.035835708931400000) * g[9] + CONSTANT(0.118853600623000000) * g[27] + CONSTANT(0.053152946071199997) * g[25];
    y[24] += tf * g[29] + tg * f[29];
    y[29] += tf * g[24] + tg * f[24];
    t = f[24] * g[29] + f[29] * g[24];
    y[9] += CONSTANT(-0.035835708931400000) * t;
    y[27] += CONSTANT(0.118853600623000000) * t;
    y[25] += CONSTANT(0.053152946071199997) * t;

    // [24,31]: 15,33,35,
    tf = CONSTANT(0.035835708931400000) * f[15] + CONSTANT(-0.118853600623000000) * f[33] + CONSTANT(0.053152946071199997) * f[35];
    tg = CONSTANT(0.035835708931400000) * g[15] + CONSTANT(-0.118853600623000000) * g[33] + CONSTANT(0.053152946071199997) * g[35];
    y[24] += tf * g[31] + tg * f[31];
    y[31] += tf * g[24] + tg * f[24];
    t = f[24] * g[31] + f[31] * g[24];
    y[15] += CONSTANT(0.035835708931400000) * t;
    y[33] += CONSTANT(-0.118853600623000000) * t;
    y[35] += CONSTANT(0.053152946071199997) * t;

    // [24,34]: 12,30,2,
    tf = CONSTANT(-0.207723503645000000) * f[12] + CONSTANT(0.130197596199999990) * f[30] + CONSTANT(0.147319200325000010) * f[2];
    tg = CONSTANT(-0.207723503645000000) * g[12] + CONSTANT(0.130197596199999990) * g[30] + CONSTANT(0.147319200325000010) * g[2];
    y[24] += tf * g[34] + tg * f[34];
    y[34] += tf * g[24] + tg * f[24];
    t = f[24] * g[34] + f[34] * g[24];
    y[12] += CONSTANT(-0.207723503645000000) * t;
    y[30] += CONSTANT(0.130197596199999990) * t;
    y[2] += CONSTANT(0.147319200325000010) * t;

    // [25,25]: 0,6,20,
    tf = CONSTANT(0.282094791761999970) * f[0] + CONSTANT(-0.242608896358999990) * f[6] + CONSTANT(0.130197596198000000) * f[20];
    tg = CONSTANT(0.282094791761999970) * g[0] + CONSTANT(-0.242608896358999990) * g[6] + CONSTANT(0.130197596198000000) * g[20];
    y[25] += tf * g[25] + tg * f[25];
    t = f[25] * g[25];
    y[0] += CONSTANT(0.282094791761999970) * t;
    y[6] += CONSTANT(-0.242608896358999990) * t;
    y[20] += CONSTANT(0.130197596198000000) * t;

    // [26,26]: 6,20,0,
    tf = CONSTANT(-0.097043558542400002) * f[6] + CONSTANT(-0.130197596207000000) * f[20] + CONSTANT(0.282094791766000000) * f[0];
    tg = CONSTANT(-0.097043558542400002) * g[6] + CONSTANT(-0.130197596207000000) * g[20] + CONSTANT(0.282094791766000000) * g[0];
    y[26] += tf * g[26] + tg * f[26];
    t = f[26] * g[26];
    y[6] += CONSTANT(-0.097043558542400002) * t;
    y[20] += CONSTANT(-0.130197596207000000) * t;
    y[0] += CONSTANT(0.282094791766000000) * t;

    // [27,27]: 0,20,6,
    tf = CONSTANT(0.282094791770000020) * f[0] + CONSTANT(-0.130197596204999990) * f[20] + CONSTANT(0.016173926423100001) * f[6];
    tg = CONSTANT(0.282094791770000020) * g[0] + CONSTANT(-0.130197596204999990) * g[20] + CONSTANT(0.016173926423100001) * g[6];
    y[27] += tf * g[27] + tg * f[27];
    t = f[27] * g[27];
    y[0] += CONSTANT(0.282094791770000020) * t;
    y[20] += CONSTANT(-0.130197596204999990) * t;
    y[6] += CONSTANT(0.016173926423100001) * t;

    // [28,28]: 6,0,20,24,
    tf = CONSTANT(0.097043558538800007) * f[6] + CONSTANT(0.282094791771999980) * f[0] + CONSTANT(-0.021699599367299999) * f[20] + CONSTANT(-0.128376561118000000) * f[24];
    tg = CONSTANT(0.097043558538800007) * g[6] + CONSTANT(0.282094791771999980) * g[0] + CONSTANT(-0.021699599367299999) * g[20] + CONSTANT(-0.128376561118000000) * g[24];
    y[28] += tf * g[28] + tg * f[28];
    t = f[28] * g[28];
    y[6] += CONSTANT(0.097043558538800007) * t;
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[20] += CONSTANT(-0.021699599367299999) * t;
    y[24] += CONSTANT(-0.128376561118000000) * t;

    // [29,29]: 20,6,0,22,8,
    tf = CONSTANT(0.086798397468799998) * f[20] + CONSTANT(0.145565337808999990) * f[6] + CONSTANT(0.282094791773999990) * f[0] + CONSTANT(-0.097043558539500002) * f[22] + CONSTANT(-0.140070311615000000) * f[8];
    tg = CONSTANT(0.086798397468799998) * g[20] + CONSTANT(0.145565337808999990) * g[6] + CONSTANT(0.282094791773999990) * g[0] + CONSTANT(-0.097043558539500002) * g[22] + CONSTANT(-0.140070311615000000) * g[8];
    y[29] += tf * g[29] + tg * f[29];
    t = f[29] * g[29];
    y[20] += CONSTANT(0.086798397468799998) * t;
    y[6] += CONSTANT(0.145565337808999990) * t;
    y[0] += CONSTANT(0.282094791773999990) * t;
    y[22] += CONSTANT(-0.097043558539500002) * t;
    y[8] += CONSTANT(-0.140070311615000000) * t;

    // [30,30]: 0,20,6,
    tf = CONSTANT(0.282094804531000000) * f[0] + CONSTANT(0.130197634486000000) * f[20] + CONSTANT(0.161739292769000010) * f[6];
    tg = CONSTANT(0.282094804531000000) * g[0] + CONSTANT(0.130197634486000000) * g[20] + CONSTANT(0.161739292769000010) * g[6];
    y[30] += tf * g[30] + tg * f[30];
    t = f[30] * g[30];
    y[0] += CONSTANT(0.282094804531000000) * t;
    y[20] += CONSTANT(0.130197634486000000) * t;
    y[6] += CONSTANT(0.161739292769000010) * t;

    // [31,31]: 6,8,20,22,0,
    tf = CONSTANT(0.145565337808999990) * f[6] + CONSTANT(0.140070311615000000) * f[8] + CONSTANT(0.086798397468799998) * f[20] + CONSTANT(0.097043558539500002) * f[22] + CONSTANT(0.282094791773999990) * f[0];
    tg = CONSTANT(0.145565337808999990) * g[6] + CONSTANT(0.140070311615000000) * g[8] + CONSTANT(0.086798397468799998) * g[20] + CONSTANT(0.097043558539500002) * g[22] + CONSTANT(0.282094791773999990) * g[0];
    y[31] += tf * g[31] + tg * f[31];
    t = f[31] * g[31];
    y[6] += CONSTANT(0.145565337808999990) * t;
    y[8] += CONSTANT(0.140070311615000000) * t;
    y[20] += CONSTANT(0.086798397468799998) * t;
    y[22] += CONSTANT(0.097043558539500002) * t;
    y[0] += CONSTANT(0.282094791773999990) * t;

    // [32,32]: 0,24,20,6,
    tf = CONSTANT(0.282094791771999980) * f[0] + CONSTANT(0.128376561118000000) * f[24] + CONSTANT(-0.021699599367299999) * f[20] + CONSTANT(0.097043558538800007) * f[6];
    tg = CONSTANT(0.282094791771999980) * g[0] + CONSTANT(0.128376561118000000) * g[24] + CONSTANT(-0.021699599367299999) * g[20] + CONSTANT(0.097043558538800007) * g[6];
    y[32] += tf * g[32] + tg * f[32];
    t = f[32] * g[32];
    y[0] += CONSTANT(0.282094791771999980) * t;
    y[24] += CONSTANT(0.128376561118000000) * t;
    y[20] += CONSTANT(-0.021699599367299999) * t;
    y[6] += CONSTANT(0.097043558538800007) * t;

    // [33,33]: 6,20,0,
    tf = CONSTANT(0.016173926423100001) * f[6] + CONSTANT(-0.130197596204999990) * f[20] + CONSTANT(0.282094791770000020) * f[0];
    tg = CONSTANT(0.016173926423100001) * g[6] + CONSTANT(-0.130197596204999990) * g[20] + CONSTANT(0.282094791770000020) * g[0];
    y[33] += tf * g[33] + tg * f[33];
    t = f[33] * g[33];
    y[6] += CONSTANT(0.016173926423100001) * t;
    y[20] += CONSTANT(-0.130197596204999990) * t;
    y[0] += CONSTANT(0.282094791770000020) * t;

    // [34,34]: 20,6,0,
    tf = CONSTANT(-0.130197596207000000) * f[20] + CONSTANT(-0.097043558542400002) * f[6] + CONSTANT(0.282094791766000000) * f[0];
    tg = CONSTANT(-0.130197596207000000) * g[20] + CONSTANT(-0.097043558542400002) * g[6] + CONSTANT(0.282094791766000000) * g[0];
    y[34] += tf * g[34] + tg * f[34];
    t = f[34] * g[34];
    y[20] += CONSTANT(-0.130197596207000000) * t;
    y[6] += CONSTANT(-0.097043558542400002) * t;
    y[0] += CONSTANT(0.282094791766000000) * t;

    // [35,35]: 6,0,20,
    tf = CONSTANT(-0.242608896358999990) * f[6] + CONSTANT(0.282094791761999970) * f[0] + CONSTANT(0.130197596198000000) * f[20];
    tg = CONSTANT(-0.242608896358999990) * g[6] + CONSTANT(0.282094791761999970) * g[0] + CONSTANT(0.130197596198000000) * g[20];
    y[35] += tf * g[35] + tg * f[35];
    t = f[35] * g[35];
    y[6] += CONSTANT(-0.242608896358999990) * t;
    y[0] += CONSTANT(0.282094791761999970) * t;
    y[20] += CONSTANT(0.130197596198000000) * t;

    // multiply count=2527

    return y;
}

HRESULT STUB_API D3DXSHEvalDirectionalLight
(
    uint32_t            Order,
    const D3DXVECTOR3*  pDir,
    float               RIntensity,
    float               GIntensity,
    float               BIntensity,
    float*              pROut,
    float*              pGOut,
    float*              pBOut
)
{
    if (!pROut)
        return kD3DERR_INVALIDCALL;

    if (Order < D3DXSH_MINORDER || Order > D3DXSH_MAXORDER)
        return kD3DERR_INVALIDCALL;

    float fTmp[D3DXSH_MAXORDER * D3DXSH_MAXORDER];

    D3DXSHEvalDirection(fTmp, Order, pDir); // evaluate the BF in this direction...

    // now compute "normalization" and scale vector for each valid spectral band
    const float fNorm = DirectX::XM_PI / CosWtInt(Order);

    const size_t numcoeff = Order * Order;

    const float fRScale = fNorm * RIntensity;

    for (size_t i = 0; i < numcoeff; ++i)
    {
        pROut[i] = fTmp[i] * fRScale;
    }

    if (pGOut)
    {
        const float fGScale = fNorm * GIntensity;

        for (size_t i = 0; i < numcoeff; ++i)
        {
            pGOut[i] = fTmp[i] * fGScale;
        }
    }

    if (pBOut)
    {
        const float fBScale = fNorm * BIntensity;

        for (size_t i = 0; i < numcoeff; ++i)
        {
            pBOut[i] = fTmp[i] * fBScale;
        }
    }

    return kD3D_OK;
}

HRESULT STUB_API D3DXSHEvalSphericalLight
(
    uint32_t            Order,
    const D3DXVECTOR3*  pPos,
    float               Radius,
    float               RIntensity,
    float               GIntensity,
    float               BIntensity,
    float*              pROut,
    float*              pGOut,
    float*              pBOut
)
{
    if (!pROut)
        return kD3DERR_INVALIDCALL;

    if (Radius < 0.f)
        return kD3DERR_INVALIDCALL;

    const float fDist = D3DXVec3Length(pPos);;

    // WARNING: fDist should not be < radius - otherwise light contains origin

    //const float fSinConeAngle = (fDist <= radius) ? 0.99999f : radius/fDist;
    const float fConeAngle = (fDist <= Radius) ? (DirectX::XM_PIDIV2) : asinf(Radius / fDist);

    D3DXVECTOR3 dir;
    D3DXVec3Normalize(&dir, pPos);

    float fTmpDir[D3DXSH_MAXORDER * D3DXSH_MAXORDER];  // rotation "vector"
    float fTmpL0[D3DXSH_MAXORDER];

    //
    // Sphere at distance fDist, the cone angle is determined by looking at the
    // right triangle with one side (the hypotenuse) beind the vector from the 
    // origin to the center of the sphere, another side is from the origin to
    // a point on the sphere whose normal is perpendicular to the given side (this
    // is one of the points on the cone that is defined by the projection of the sphere
    // through the origin - we want to find the angle of this cone) and the final
    // side being from the center of the sphere to the point of tagency (the two
    // sides conected to this are at a right angle by construction.)
    // From trig we know that sin(theta) = ||opposite||/||hypotenuse||, where
    // ||opposite|| = Radius, ||hypotenuse|| = fDist
    // theta is the angle of the cone that subtends the sphere from the origin
    //

    // no default normalization is done for this case, have to be careful how
    // you represent the coefficients...

    const float fNewNorm = 1.0f;///(fSinConeAngle*fSinConeAngle); 

    ComputeCapInt(Order, fConeAngle, fTmpL0);

    const float fX = dir.x;
    const float fY = dir.y;
    const float fZ = dir.z;

    switch (Order)
    {
    case 2:
        sh_eval_basis_1(fX, fY, fZ, fTmpDir);
        break;

    case 3:
        sh_eval_basis_2(fX, fY, fZ, fTmpDir);
        break;

    case 4:
        sh_eval_basis_3(fX, fY, fZ, fTmpDir);
        break;

    case 5:
        sh_eval_basis_4(fX, fY, fZ, fTmpDir);
        break;

    case 6:
        sh_eval_basis_5(fX, fY, fZ, fTmpDir);
        break;

    default:
        assert(Order < D3DXSH_MINORDER || Order > D3DXSH_MAXORDER);
        return kD3DERR_INVALIDCALL;
    }


    for (size_t i = 0; i < Order; ++i)
    {
        const size_t cNumCoefs = 2 * i + 1;
        const size_t cStart = i * i;
        const float fValUse = fTmpL0[i] * RIntensity * fNewNorm * fExtraNormFac[i];
        for (size_t j = 0; j < cNumCoefs; ++j) pROut[cStart + j] = fTmpDir[cStart + j] * fValUse;
    }

    if (pGOut)
    {
        for (size_t i = 0; i < Order; ++i)
        {
            const size_t cNumCoefs = 2 * i + 1;
            const size_t cStart = i * i;
            const float fValUse = fTmpL0[i] * GIntensity * fNewNorm * fExtraNormFac[i];
            for (size_t j = 0; j < cNumCoefs; ++j) pGOut[cStart + j] = fTmpDir[cStart + j] * fValUse;
        }
    }

    if (pBOut)
    {
        for (size_t i = 0; i < Order; ++i)
        {
            const size_t cNumCoefs = 2 * i + 1;
            const size_t cStart = i * i;
            const float fValUse = fTmpL0[i] * BIntensity * fNewNorm * fExtraNormFac[i];
            for (size_t j = 0; j < cNumCoefs; ++j) pBOut[cStart + j] = fTmpDir[cStart + j] * fValUse;
        }
    }

    return kD3D_OK;
}

HRESULT STUB_API D3DXSHEvalConeLight
(
    uint32_t            Order,
    const D3DXVECTOR3*  pDir,
    float               Radius,
    float               RIntensity,
    float               GIntensity,
    float               BIntensity,
    float*              pROut,
    float*              pGOut,
    float*              pBOut
)
{
    if (!pROut)
        return kD3DERR_INVALIDCALL;

    if (Radius < 0.f || Radius >(DirectX::XM_PI * 1.00001f))
        return kD3DERR_INVALIDCALL;

    if (Radius < 0.0001f)
    {
        // turn it into a pure directional light...
        return D3DXSHEvalDirectionalLight(Order, pDir, RIntensity, GIntensity, BIntensity, pROut, pGOut, pBOut);
    }
    else
    {
        float fTmpL0[D3DXSH_MAXORDER];
        float fTmpDir[D3DXSH_MAXORDER * D3DXSH_MAXORDER];

        const float fConeAngle = Radius;
        const float fAngCheck = (fConeAngle > DirectX::XM_PIDIV2) ? (DirectX::XM_PIDIV2) : fConeAngle;

        const float fNewNorm = 1.0f / (sinf(fAngCheck) * sinf(fAngCheck));

        ComputeCapInt(Order, fConeAngle, fTmpL0);

        const float fX = pDir->x;
        const float fY = pDir->y;
        const float fZ = pDir->z;

        switch (Order)
        {
        case 2:
            sh_eval_basis_1(fX, fY, fZ, fTmpDir);
            break;

        case 3:
            sh_eval_basis_2(fX, fY, fZ, fTmpDir);
            break;

        case 4:
            sh_eval_basis_3(fX, fY, fZ, fTmpDir);
            break;

        case 5:
            sh_eval_basis_4(fX, fY, fZ, fTmpDir);
            break;

        case 6:
            sh_eval_basis_5(fX, fY, fZ, fTmpDir);
            break;

        default:
            assert(Order < D3DXSH_MINORDER || Order > D3DXSH_MAXORDER);
            return kD3DERR_INVALIDCALL;
        }

        for (size_t i = 0; i < Order; ++i)
        {
            const size_t cNumCoefs = 2 * i + 1;
            const size_t cStart = i * i;
            const float fValUse = fTmpL0[i] * RIntensity * fNewNorm * fExtraNormFac[i];
            for (size_t j = 0; j < cNumCoefs; ++j)
                pROut[cStart + j] = fTmpDir[cStart + j] * fValUse;
        }

        if (pGOut)
        {
            for (size_t i = 0; i < Order; ++i)
            {
                const size_t cNumCoefs = 2 * i + 1;
                const size_t cStart = i * i;
                const float fValUse = fTmpL0[i] * GIntensity * fNewNorm * fExtraNormFac[i];
                for (size_t j = 0; j < cNumCoefs; ++j)
                    pGOut[cStart + j] = fTmpDir[cStart + j] * fValUse;
            }
        }

        if (pBOut)
        {
            for (size_t i = 0; i < Order; ++i)
            {
                const size_t cNumCoefs = 2 * i + 1;
                const size_t cStart = i * i;
                const float fValUse = fTmpL0[i] * BIntensity * fNewNorm * fExtraNormFac[i];
                for (size_t j = 0; j < cNumCoefs; ++j)
                    pBOut[cStart + j] = fTmpDir[cStart + j] * fValUse;
            }
        }
    }

    return kD3D_OK;
}

HRESULT STUB_API D3DXSHEvalHemisphereLight
(
    uint32_t            Order,
    const D3DXVECTOR3*  pDir,
    D3DXCOLOR           Top,
    D3DXCOLOR           Bottom,
    float*              pROut,
    float*              pGOut,
    float*              pBOut
)
{
    if (!pROut)
        return kD3DERR_INVALIDCALL;

    if (Order < D3DXSH_MINORDER || Order > D3DXSH_MAXORDER)
        return kD3DERR_INVALIDCALL;

    // seperate "R/G/B colors...

    float fTmpDir[D3DXSH_MAXORDER * D3DXSH_MAXORDER];  // rotation "vector"
    float fTmpL0[D3DXSH_MAXORDER];

    const float fNewNorm = 3.0f / 2.0f; // normalizes things for 1 sky color, 0 ground color...

    const float fX = pDir->x;
    const float fY = pDir->y;
    const float fZ = pDir->z;

    sh_eval_basis_1(fX, fY, fZ, fTmpDir);


    float fA = Top.r;
    float fAvrg = (Top.r + Bottom.r) * 0.5f;

    fTmpL0[0] = fAvrg * 2.0f * SHEvalHemisphereLight_fSqrtPi;
    fTmpL0[1] = (fA - fAvrg) * 2.0f * SHEvalHemisphereLight_fSqrtPi3;

    size_t i = 0;
    for (; i < 2; ++i)
    {
        _Analysis_assume_(i < order);
        const size_t cNumCoefs = 2 * i + 1;
        const size_t cStart = i * i;
        const float fValUse = fTmpL0[i] * fNewNorm * fExtraNormFac[i];
        for (size_t j = 0; j < cNumCoefs; ++j) pROut[cStart + j] = fTmpDir[cStart + j] * fValUse;
    }

    for (; i < Order; ++i)
    {
        const size_t cNumCoefs = 2 * i + 1;
        const size_t cStart = i * i;
        for (size_t j = 0; j < cNumCoefs; ++j) pROut[cStart + j] = 0.0f;
    }

    if (pGOut)
    {
        fA = Top.g;
        fAvrg = (Top.g + Bottom.g) * 0.5f;

        fTmpL0[0] = fAvrg * 2.0f * SHEvalHemisphereLight_fSqrtPi;
        fTmpL0[1] = (fA - fAvrg) * 2.0f * SHEvalHemisphereLight_fSqrtPi3;

        for (i = 0; i < 2; ++i)
        {
            _Analysis_assume_(i < order);
            const size_t cNumCoefs = 2 * i + 1;
            const size_t cStart = i * i;
            const float fValUse = fTmpL0[i] * fNewNorm * fExtraNormFac[i];
            for (size_t j = 0; j < cNumCoefs; ++j) pGOut[cStart + j] = fTmpDir[cStart + j] * fValUse;
        }

        for (; i < Order; ++i)
        {
            const size_t cNumCoefs = 2 * i + 1;
            const size_t cStart = i * i;
            for (size_t j = 0; j < cNumCoefs; ++j) pGOut[cStart + j] = 0.0f;
        }
    }

    if (pBOut)
    {
        fA = Top.b;
        fAvrg = (Top.b + Bottom.b) * 0.5f;

        fTmpL0[0] = fAvrg * 2.0f * SHEvalHemisphereLight_fSqrtPi;
        fTmpL0[1] = (fA - fAvrg) * 2.0f * SHEvalHemisphereLight_fSqrtPi3;

        for (i = 0; i < 2; ++i)
        {
            _Analysis_assume_(i < order);
            const size_t cNumCoefs = 2 * i + 1;
            const size_t cStart = i * i;
            const float fValUse = fTmpL0[i] * fNewNorm * fExtraNormFac[i];
            for (size_t j = 0; j < cNumCoefs; ++j) pBOut[cStart + j] = fTmpDir[cStart + j] * fValUse;
        }

        for (; i < Order; ++i)
        {
            const size_t cNumCoefs = 2 * i + 1;
            const size_t cStart = i * i;
            for (size_t j = 0; j < cNumCoefs; ++j) pBOut[cStart + j] = 0.0f;
        }
    }

    return kD3D_OK;
}


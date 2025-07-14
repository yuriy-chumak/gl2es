Built-in Variables
-----------------------------------

### Vertex Shader Special Variables
* gl_Position
* gl_PointSize (full)

### Fragment Shader Special Variables
* gl_FragCoord
* gl_FrontFacing (full)
* gl_FragColor
* gl_FragData[gl_MaxDrawBuffers]
* gl_FragDepth (GLES 3.0)
* gl_PointCoord (full)

### Vertex Shader Built-In Attributes
There are no built-in attribute names in OpenGL ES.

### Built-In Constants
* gl_MaxVertexAttribs
* gl_MaxVertexUniformVectors
* gl_MaxVaryingVectors
* gl_MaxVertexTextureImageUnits
* gl_MaxCombinedTextureImageUnits
* gl_MaxTextureImageUnits
* gl_MaxFragmentUniformVectors
* gl_MaxDrawBuffers

### Built-In Uniform State
* gl_DepthRange


GL2ES Variables
----------------------------------------------------------------------------
TODO: add https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.60.html

### Vertex Shader Special Variables
* ~~gl_Position~~
* ~~gl_PointSize~~
* gl_ClipVertex

### Vertex Shader Attribute Inputs
* gl_Vertex
* gl_Normal
* gl_Color
* gl_SecondaryColor
* gl_MultiTexCoord0
* gl_MultiTexCoord1
* gl_MultiTexCoord2
* gl_MultiTexCoord3
* gl_MultiTexCoord4
* gl_MultiTexCoord5
* gl_MultiTexCoord6
* gl_MultiTexCoord7
* gl_FogCoord

### Vertex Shader Varying Outputs
* gl_FrontColor
* gl_BackColor
* gl_FrontSecondaryColor
* gl_BackSecondaryColor
* gl_TexCoord[gl_MaxTextureCoords]
* gl_FogFragCoord

### Fragment Shader Special Variables
* ~~gl_FragColor~~
* ~~gl_FragData[gl_MaxDrawBuffers]~~
* ~~gl_FragDepth~~

### Fragment Shader Varying Inputs
* gl_Color
* gl_SecondaryColor
* gl_TexCoord[gl_MaxTextureCoords]
* gl_FogFragCoord

### Fragment Shader Special Input Variables
* ~~gl_FragCoord~~
* ~~gl_FrontFacing~~

### Built-In Constants
* gl_MaxVertexUniformComponents
* gl_MaxFragmentUniformComponents
* ~~gl_MaxVertexAttribs~~
* gl_MaxVaryingFloats
* ~~gl_MaxDrawBuffers~~
* gl_MaxTextureCoords
* gl_MaxTextureUnits
* ~~gl_MaxTextureImageUnits~~
* ~~gl_MaxVertexTextureImageUnits~~
* gl_MaxCombinedTextureImageUnits
* gl_MaxLights
* gl_MaxClipPlanes

### Built-In Uniforms

* gl_ModelViewMatrix
* gl_ModelViewProjectionMatrix
* gl_ProjectionMatrix
* gl_TextureMatrix[gl_MaxTextureCoords]
* gl_ModelViewMatrixInverse
* gl_ModelViewProjectionMatrixInverse
* gl_ProjectionMatrixInverse
* gl_TextureMatrixInverse[gl_MaxTextureCoords]
* gl_ModelViewMatrixTranspose
* gl_ModelViewProjectionMatrixTranspose
* gl_ProjectionMatrixTranspose
* gl_TextureMatrixTranspose[gl_MaxTextureCoords]
* gl_ModelViewMatrixInverseTranspose
* gl_ModelViewProjectionMatrixInverseTranspose
* gl_ProjectionMatrixInverseTranspose
* gl_TextureMatrixInverseTranspose[gl_MaxTextureCoords]
* gl_NormalMatrix
* gl_NormalScale

* ~~gl_DepthRange~~
* gl_Fog
* gl_LightSource[gl_MaxLights]
* gl_LightModel
* gl_FrontLightModelProduct
* gl_BackLightModelProduct
* gl_FrontLightProduct[gl_MaxLights
* gl_BackLightProduct[gl_MaxLights]
* gl_FrontMaterial
* gl_BackMaterial
* gl_Point
* gl_TextureEnvColor[gl_MaxTextureUnits]

* gl_ClipPlane[gl_MaxClipPlanes]
* gl_EyePlaneS[gl_MaxTextureCoords]
* gl_EyePlaneT[gl_MaxTextureCoords]
* gl_EyePlaneR[gl_MaxTextureCoords]
* gl_EyePlaneQ[gl_MaxTextureCoords]
* gl_ObjectPlaneS[gl_MaxTextureCoords]
* gl_ObjectPlaneT[gl_MaxTextureCoords]
* gl_ObjectPlaneR[gl_MaxTextureCoords]
* gl_ObjectPlaneQ[gl_MaxTextureCoords]

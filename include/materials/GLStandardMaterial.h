//
//  GLStandardMaterial.h
//  GLEngineExamples
//
//  Created by Asger Nyman Christiansen on 21/12/2016.
//  Copyright © 2016 Asger Nyman Christiansen. All rights reserved.
//

#pragma once

#include "GLMaterial.h"

namespace gle
{
    class GLStandardMaterial : public GLMaterial
    {
    public:
        
        GLStandardMaterial(const glm::vec3& _ambient, const glm::vec3& _diffuse, const glm::vec3& _specular, double _opacity)
        {
            shader = GLShader::create_or_get("../GLEngine/shaders/phong.vert",  "../GLEngine/shaders/phong.frag");
            
            use_uniform("VMatrix", view);
            use_uniform("MVMatrix", modelView);
            use_uniform("NMatrix", inverseModelView);
            use_uniform("MVPMatrix", modelViewProjection);
            use_uniform("lightPos", glm::vec3(5., 5., 5.));
            use_uniform("ambientMat", _ambient);
            use_uniform("diffuseMat", _diffuse);
            use_uniform("specMat", _specular);
            use_uniform("opacity", _opacity);
            
            test_depth = _opacity >= 0.999;
        }
        
        void create_attributes(std::shared_ptr<mesh::Mesh> geometry, std::vector<std::shared_ptr<GLVertexAttribute<glm::vec2>>>& vec2_vertex_attributes,
                               std::vector<std::shared_ptr<GLVertexAttribute<glm::vec3>>>& vec3_vertex_attributes)
        {
            vec3_vertex_attributes.push_back(shader->create_attribute("position", geometry->position()));
            vec3_vertex_attributes.push_back(shader->create_attribute("normal", geometry->normal()));
        }
    };
}

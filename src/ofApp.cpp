#include "ofApp.h"












//--------------------------------------------------------------
void ofApp::setup(){
    
    //   GLsizei const vertexCount(4);
//    ofVec3f const vertexData[vertexCount] = {
//    
//        ofVec3f(-1.0f,-1.0f,0.0f),
//        ofVec3f(1.0f,-1.0f,0.0f),
//        ofVec3f(1.0f,1.0f,0.0f),
//        ofVec3f(-1.0f,1.0f,0.0f),
//    
//    };
//    
//    ofFloatColor const colorData[vertexCount] = {
//    
//        ofFloatColor(1.0f, 0.0f, 0.0f, 1.0f),
//        ofFloatColor(1.0f, 1.0f, 0.0f, 1.0f),
//        ofFloatColor(0.0f, 1.0f, 0.0f, 1.0f),
//        ofFloatColor(0.0f, 0.0f, 1.0f, 1.0f)
//    
//    };
//    
    
    

    mTessellationShader.setupShaderFromFile(GL_VERTEX_SHADER, "tess.vert");
    mTessellationShader.setupShaderFromFile(GL_FRAGMENT_SHADER, "tess.frag");
    mTessellationShader.setupShaderFromFile(GL_GEOMETRY_SHADER, "tess.geom");
    mTessellationShader.setupShaderFromFile(GL_TESS_CONTROL_SHADER, "tess.cont");
    mTessellationShader.setupShaderFromFile(GL_TESS_EVALUATION_SHADER, "tess.eval");
    mTessellationShader.linkProgram();
    
    mVbo.enableVAOs();
    mVbo.enableColors();
//    mVbo.setVertexData(vertexData, 4, GL_STATIC_DRAW);
//    mVbo.setColorData(colorData, 4, GL_STATIC_DRAW);
    mVbo.setMesh(ofMesh::sphere(1.0f, 4, OF_PRIMITIVE_TRIANGLES), GL_STATIC_DRAW, true, false, false);
    
    // main camera
    mCam.lookAt(ofVec3f::zero());
    mCam.setPosition(0, 0, 4);
    mCam.setFarClip(100);
    mCam.setNearClip(0.01);
    mCam.setDistance(4);
    mCam.enableMouseInput();


}

//--------------------------------------------------------------
void ofApp::update(){
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofClear(0, 0, 0);
    ofViewport(ofGetWindowRect());
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    mCam.begin();
    mTessellationShader.begin();
    mTessellationShader.setUniformMatrix4f("MVP", mCam.getModelViewProjectionMatrix());
    mVbo.bind();
    glPatchParameteri(GL_PATCH_VERTICES, 3);
    mVbo.drawElements(GL_PATCHES, mVbo.getNumIndices());
    //  mVbo.drawInstanced(GL_PATCHES, 0, mVbo.getNumVertices(), 1);
    mCam.end();
    
    
    //    glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, WindowSize.x / WindowSize.y, 0.1f, 100.0f);
    //    glm::mat4 Model = glm::mat4(1.0f);
    //    glm::mat4 MVP = Projection * this->view() * Model;
    //
    //    glViewport(0, 0, static_cast<GLsizei>(WindowSize.x), static_cast<GLsizei>(WindowSize.y));
    //    glClearBufferfv(GL_COLOR, 0, &glm::vec4(0.0f)[0]);
    //
    //    glUseProgram(ProgramName);
    //    glUniformMatrix4fv(UniformMVP, 1, GL_FALSE, &MVP[0][0]);
    //
    //    glBindVertexArray(VertexArrayName);
    //    glPatchParameteri(GL_PATCH_VERTICES, VertexCount);
    //    glPatchParameterfv(GL_PATCH_DEFAULT_INNER_LEVEL, &glm::vec2(16.f)[0]);
    //    glPatchParameterfv(GL_PATCH_DEFAULT_OUTER_LEVEL, &glm::vec4(16.f)[0]);
    //    glDrawArraysInstanced(GL_PATCHES, 0, VertexCount, 1);
    //    
    //
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

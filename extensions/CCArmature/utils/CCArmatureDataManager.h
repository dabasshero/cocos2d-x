/****************************************************************************
Copyright (c) 2013 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CCARMATUREDATAMANAGER_H__
#define __CCARMATUREDATAMANAGER_H__

#include "CCArmatureDefine.h"
#include "CCConstValue.h"
#include "../datas/CCDatas.h"


namespace cocos2d { namespace extension { namespace armature {

/**
 *	@brief	format and manage armature configuration and armature animation
 */
class  CCArmatureDataManager : public CCObject 
{
public:
    static CCArmatureDataManager *sharedArmatureDataManager();
    static void purgeArmatureSystem();
private:
    CCArmatureDataManager(void);
    ~CCArmatureDataManager(void);

public:
	/**
     * Init CCArmatureDataManager
     */
    virtual bool init();
    
    /**
     * Add armature data
     * @param id The id of the armature data
	 * @param armatureData CCArmatureData *
     */
    void addArmatureData(const char *id, CCArmatureData *armatureData);
    
	/**
     *	@brief	get armature data
     *
     *	@param	id the id of the armature data you want to get
	 *  
	 *  @return	CCArmatureData *
     */
    CCArmatureData *getArmatureData(const char *id);

    /**
     *	@brief	add animation data 
     *
     *	@param 	id the id of the animation data 
	 *
	 *  @return CCAnimationData *
     */
    void addAnimationData(const char *id, CCAnimationData *animationData);
    
	/**
     *	@brief	get animation data from _animationDatas(CCDictionary)
     *
     *	@param 	id the id of the animation data you want to get
	 *  
	 *  @return CCAnimationData *
     */
    CCAnimationData *getAnimationData(const char *id);

    /**
     *	@brief	add texture data 
     *
     *	@param 	id the id of the texture data
	 *
	 *  @return CCTextureData *
     */
    void addTextureData(const char *id, CCTextureData *textureData);
    
	/**
     *	@brief	get texture data
     *
     *	@param 	_id the id of the texture data you want to get
	 *  
	 *  @return CCTextureData *
     */
    CCTextureData *getTextureData(const char *id);
    
    /**
	 *	@brief	Add ArmatureFileInfo, it is managed by CCArmatureDataManager.
     */
	void addArmatureFileInfo(const char *armatureName, const char *useExistFileInfo, const char *imagePath, const char *plistPath, const char *configFilePath);
    /**
	 *	@brief	Add ArmatureFileInfo, it is managed by CCArmatureDataManager.
     */
	void addArmatureFileInfo(const char *imagePath, const char *plistPath, const char *configFilePath);

    /**
     *	@brief	Add sprite frame to CCSpriteFrameCache, it will save display name and it's relative image name
     */
    void addSpriteFrameFromFile(const char *plistPath, const char *imagePath);
    
	
	/**
	 *	@brief	Clear the data in the _armarureDatas and _animationDatas, and set _armarureDatas and _animationDatas to NULL
     */
    void removeAll();

   
private:
    /**
	 *	@brief	save amature datas
	 *  @key	std::string
	 *  @value	CCArmatureData *
     */
	CC_SYNTHESIZE_READONLY(CCDictionary *, _armarureDatas, ArmarureDatas);

    /**
	 *	@brief	save animation datas
	 *  @key	std::string
	 *  @value	CCAnimationData *
     */
	CC_SYNTHESIZE_READONLY(CCDictionary *, _animationDatas, AnimationDatas);

	/**
	 *	@brief	save texture datas
	 *  @key	std::string
	 *  @value	CCTextureData *
     */
	CC_SYNTHESIZE_READONLY(CCDictionary *, _textureDatas, TextureDatas);

};


}}} // namespace cocos2d { namespace extension { namespace armature {

#endif/*__CCARMATUREDATAMANAGER_H__*/

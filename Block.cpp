
#include "Block.h"

Block::Block() {
	id=1;
	type = step;
	position = 0;
}

Block::Block(Ogre::SceneManager *newManager, int num, int z, bool m, bool s) {
	id = num;
	int temp = rand()%4;
	switch(temp) {
		case (0): 
		type = step;
		break;
		case (1): 
		type = ceiling;
		break;
		case (2): 
		type = gap;
		break;
		case (3):
		type = rail;
		break;
		case (4):
		type = sideRun;
		break;
	}
	position = z;
	multi = m;
	serv = s;
	blockManager = newManager;
	buildBlock();
}

/*void Block::setPos(int x, int y, int z) {
	blockNode->setPosition(x, y, z);
}

Ogre::Vector3 Block::getPos() {
	return Ogre::Vector3(blockNode->getPosition().x, blockNode->getPosition().y, blockNode->getPosition().z);
}*/

int Block::destroy()
{
	return 0;
}


int Block::getID()
{
	return id;
}


void Block::buildBlock() {	
	if(type == step) {
		blockNode1 = blockManager->getRootSceneNode()->createChildSceneNode();
		blockNode1->setPosition(0,25,position);
		blockNode1->setScale(75,25,50);
		blockEntity1 = blockManager->createEntity("block"+id, "Wood.mesh");
		blockEntity1->setCastShadows(true);
		blockNode1->attachObject(blockEntity1);
	}
	else if(type == ceiling) {
		blockNode1 = blockManager->getRootSceneNode()->createChildSceneNode();
		blockNode1->setPosition(0,115,position+100);
		blockNode1->setScale(75,100,200);
		blockEntity1 = blockManager->createEntity("block"+id, "Brick.mesh");
		blockEntity1->setCastShadows(true);
		blockNode1->attachObject(blockEntity1);
		
		blockNode2 = blockManager->getRootSceneNode()->createChildSceneNode();
		blockNode2->setPosition(-175,105,position+100);
		blockNode2->setScale(40,25,200);
		blockEntity2 = blockManager->createEntity("blockleft"+id, "Brick.mesh");
		blockEntity2->setCastShadows(true);
		blockNode2->setOrientation(Ogre::Quaternion((Ogre::Radian)PI/2, Ogre::Vector3(0.0, 0.0, 1.0)));
		blockNode2->attachObject(blockEntity2);
			
		blockNode3 = blockManager->getRootSceneNode()->createChildSceneNode();
		blockNode3->setPosition(175,105,position+100);
		blockNode3->setScale(40,25,200);
		blockEntity3 = blockManager->createEntity("blockright"+id, "Brick.mesh");
		blockEntity3->setCastShadows(true);
		blockNode3->setOrientation(Ogre::Quaternion((Ogre::Radian)PI/2, Ogre::Vector3(0.0, 0.0, 1.0)));
		blockNode3->attachObject(blockEntity3);
	}
	else if(type == gap) {
		if(multi) {
			blockNode1 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode1->setPosition(150,100,position);
			blockNode1->setScale(15,100,200);
			blockEntity1 = blockManager->createEntity("block"+id, "Brick.mesh");
			blockEntity1->setCastShadows(true);
			blockNode1->attachObject(blockEntity1);
	
			blockNode2 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode2->setPosition(50,100,position);
			blockNode2->setScale(15,100,200);
			blockEntity2 = blockManager->createEntity("blockleft"+id, "Brick.mesh");
			blockEntity2->setCastShadows(true);
			blockNode2->attachObject(blockEntity2);

			blockNode3 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode3->setPosition(-50,100,position);
			blockNode3->setScale(15,100,200);
			blockEntity3 = blockManager->createEntity("blockmiddle"+id, "Brick.mesh");
			blockEntity3->setCastShadows(true);
			blockNode3->attachObject(blockEntity3);

			blockNode4 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode4->setPosition(-150,100,position);
			blockNode4->setScale(15,100,200);
			blockEntity4 = blockManager->createEntity("blockright"+id, "Brick.mesh");
			blockEntity4->setCastShadows(true);
			blockNode4->attachObject(blockEntity4);
		}
		else {
			blockNode1 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode1->setPosition(50,100,position);
			blockNode1->setScale(15,100,200);
			blockEntity1 = blockManager->createEntity("block"+id, "Brick.mesh");
			blockEntity1->setCastShadows(true);
			blockNode1->attachObject(blockEntity1);
	
			blockNode2 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode2->setPosition(-50,100,position);
			blockNode2->setScale(15,100,200);
			blockEntity2 = blockManager->createEntity("blockright"+id, "Brick.mesh");
			blockEntity2->setCastShadows(true);
			blockNode2->attachObject(blockEntity2);
		}
	}
	else if(type == rail) {
		if(multi) {
			blockNode1 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode1->setScale(5,25,400);
			blockEntity1 = blockManager->createEntity("block"+id, "Metal.mesh");
			blockEntity1->setCastShadows(true);
			blockNode1->attachObject(blockEntity1);

			blockNode2 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode2->setScale(5,25,400);
			blockEntity2 = blockManager->createEntity("blockright"+id, "Metal.mesh");
			blockEntity2->setCastShadows(true);
			blockNode2->attachObject(blockEntity2);
			
			if(serv) {
				blockNode1->setPosition(100,25,position+350);
				blockNode2->setPosition(-100,25,position+350);
			}
			else {
				blockNode2->setPosition(100,25,position+350);
				blockNode1->setPosition(-100,25,position+350);
			}
		}
		else {
			blockNode1 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode1->setPosition(0,25,position+350);
			blockNode1->setScale(5,25,400);
			blockEntity1 = blockManager->createEntity("block"+id, "Metal.mesh");
			blockEntity1->setCastShadows(true);
			blockNode1->attachObject(blockEntity1);
		}
	}
		/*case sideRun: 
			blockNode1 = blockManager->getRootSceneNode()->createChildSceneNode();
			blockNode1->setPosition(-100,100,position+350);
			blockNode1->setScale(15,100,400);
			blockEntity1 = blockManager->createEntity("block"+id, "Metal.mesh");
			blockEntity1->setCastShadows(true);
			blockNode1->attachObject(blockEntity1);
		break;*/
}

void Block::setPosition(int x, int y, int z) {
	blockNode1->setPosition(Ogre::Vector3(x, y, z));
}
btVector3 Block::getPosition() {
	int x = blockNode1->getPosition().x;
	int y = blockNode1->getPosition().y;
	int z = blockNode1->getPosition().z;
	return btVector3(x,y,z);
}
int Block::getZ() {
	return position;
}
int Block::getType() {
	if(type==step){
		return 0;
	}
	else if(type==ceiling) {
		return 1;
	}
	else if(type==gap) {
		return 2;
	}
	else if(type==rail) {
		return 3;
	}
	else if(type==sideRun)
		return 4;
	else return 0;
}

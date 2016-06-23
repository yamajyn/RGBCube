#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define KEY_ESC 27 

int rotateX = 0;
int rotateY = 0;

void display( void )
{
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
glEnable( GL_DEPTH_TEST );
glPushMatrix();
glTranslatef(0.0, 0.0, -3.0);
glPushMatrix();
	glRotatef(rotateX,1,0,0);
	glRotatef(rotateY,0,1,0);

	//RGB

	//Blue
	glPushMatrix();
		glScalef(1.,1.,1.);
		glBegin( GL_POLYGON );
			glColor3f( 1.0, 1.0, 1.0 );
			glVertex3f( 0.5, 0.5, 0.5 );
			glColor3f( 0.0, 1.0, 1.0 );
			glVertex3f(-0.5, 0.5, 0.5 );
			glColor3f( 0.0, 0.0, 1.0 );
			glVertex3f(-0.5,-0.5, 0.5 );
			glColor3f( 1.0, 0.0, 1.0 );
			glVertex3f( 0.5,-0.5, 0.5 );
		glEnd();
	glPopMatrix();


	//Red
	glPushMatrix();
		glRotatef(90,0,1,0);
	
		glBegin( GL_POLYGON );
			glColor3f( 1.0, 1.0, 0.0 );
			glVertex3f( 0.5, 0.5, 0.5 );
			glColor3f( 1.0, 1.0, 1.0 );
			glVertex3f(-0.5, 0.5, 0.5 );
			glColor3f( 1.0, 0.0, 1.0 );
			glVertex3f(-0.5,-0.5, 0.5 );
			glColor3f( 1.0, 0.0, 0.0 );
			glVertex3f( 0.5,-0.5, 0.5 );
		glEnd();
	glPopMatrix();

	//Green
	glPushMatrix();
		glRotatef(-90,1,0,0);
		glBegin( GL_POLYGON );
			glColor3f( 1.0, 1.0, 0.0 );
			glVertex3f( 0.5, 0.5, 0.5 );
			glColor3f( 0.0, 1.0, 0.0 );
			glVertex3f(-0.5, 0.5, 0.5 );
			glColor3f( 0.0, 1.0, 1.0 );
			glVertex3f(-0.5,-0.5, 0.5 );
			glColor3f( 1.0, 1.0, 1.0 );
			glVertex3f( 0.5,-0.5, 0.5 );
		glEnd();
	glPopMatrix();


	//DarkRGB

	//Blue
	glPushMatrix();
		glScalef(1.,1.,1.);
		glRotatef(90,1,0,0);
		glBegin( GL_POLYGON );
			glColor3f( 1.0, 0.0, 1.0  );
			glVertex3f( 0.5, 0.5, 0.5 );
			glColor3f( 0.0, 0.0, 1.0 );
			glVertex3f(-0.5, 0.5, 0.5 );
			glColor3f( 0.0, 0.0, 0.0 );
			glVertex3f(-0.5,-0.5, 0.5 );
			glColor3f( 1.0, 0.0, 0.0 );
			glVertex3f( 0.5,-0.5, 0.5 );
		glEnd();
	glPopMatrix();


	//Red
	glPushMatrix();
		glRotatef(-90,0,1,0);
	
		glBegin( GL_POLYGON );
			glColor3f( 0.0, 1.0, 1.0 );
			glVertex3f( 0.5, 0.5, 0.5 );
			glColor3f( 0.0, 1.0, 0.0 );
			glVertex3f(-0.5, 0.5, 0.5 );
			glColor3f( 0.0, 0.0, 0.0 );
			glVertex3f(-0.5,-0.5, 0.5 );
			glColor3f( 0.0, 0.0, 1.0 );
			glVertex3f( 0.5,-0.5, 0.5 );
		glEnd();
	glPopMatrix();


	//Green
	glPushMatrix();
		glRotatef(-180,1,0,0);
		glBegin( GL_POLYGON );
			glColor3f( 1.0, 0.0, 0.0 );
			glVertex3f( 0.5, 0.5, 0.5 );
			glColor3f( 0.0, 0.0, 0.0 );
			glVertex3f(-0.5, 0.5, 0.5 );
			glColor3f( 0.0, 1.0, 0.0 );
			glVertex3f(-0.5,-0.5, 0.5 );
			glColor3f( 1.0, 1.0, 0.0 );
			glVertex3f( 0.5,-0.5, 0.5 );
		glEnd();
	glPopMatrix();

glPopMatrix();
glPopMatrix();

glDisable( GL_DEPTH_TEST );

glFlush();
}


void myKbd( unsigned char key, int x, int y )
{
	if ( key == KEY_ESC ) exit( 0 );
	
	
}

void mySkey( int key,int x, int y){
	if ( key == GLUT_KEY_UP ){ 
		rotateX -=3;
		glutPostRedisplay();
	}
	else if ( key == GLUT_KEY_DOWN ){ 
		rotateX +=3;
		glutPostRedisplay();
	}
	else if ( key == GLUT_KEY_LEFT ){ 
		rotateY +=3;
		glutPostRedisplay();
	}
	else if ( key == GLUT_KEY_RIGHT ){ 
		rotateY -=3;
		glutPostRedisplay();
	}
}


void myInit ( char *progname )
{
	int width = 500, height = 500;
	float aspect = (float) width / (float) height;

	glutInitWindowPosition( 0, 0 ); 
	glutInitWindowSize( width, height );
	glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH);
	glutCreateWindow( progname );

	glClearColor ( 0.0, 0.0, 0.0, 1.0 );
	glutKeyboardFunc( myKbd );
	glutSpecialFunc( mySkey );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45.0, aspect, 1.0, 7.0 );
	glMatrixMode( GL_MODELVIEW );
}


int main( int argc, char** argv )
{
	glutInit( &argc, argv );
	myInit( argv[0] );
	glutDisplayFunc( display );
	glutMainLoop();
	return( 0 );
}

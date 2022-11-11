#include "qte.h"
#include "implicits.h"
#include "ui_interface.h"
#include <chrono>

/*!
\brief Creates the User's window.
*/
MainWindow::MainWindow() : QMainWindow(), uiw(new Ui::Assets)
{
    // Chargement de l'interface
    uiw->setupUi(this);

    // Chargement du GLWidget
    meshWidget = new MeshWidget;
    QGridLayout* GLlayout = new QGridLayout;
    GLlayout->addWidget(meshWidget, 0, 0);
    GLlayout->setContentsMargins(0, 0, 0, 0);
    uiw->widget_GL->setLayout(GLlayout);

    // Creation des connect
    CreateActions();

    meshWidget->SetCamera(Camera(Vector(10, 0, 0), Vector(0.0, 0.0, 0.0)));
}

/*!
\brief Deletes the User's window on the heap.
*/
MainWindow::~MainWindow()
{
    delete meshWidget;
}

/*!
\brief Links User's'actions on the Interface with associated functions.
*/
void MainWindow::CreateActions()
{
    // Buttons
    connect(uiw->boxMesh, SIGNAL(clicked()), this, SLOT(BoxMeshExample()));
    connect(uiw->sphereMesh, SIGNAL(clicked()),this,SLOT(SphereMeshExemple()));
    connect(uiw->torusMesh, SIGNAL(clicked()),this,SLOT(TorusMeshExemple()));
    connect(uiw->cylinderMesh, SIGNAL(clicked()),this,SLOT(CylindreMeshExemple()));
    connect(uiw->capsuleMesh, SIGNAL(clicked()),this,SLOT(CapsuleMeshExemple()));
    connect(uiw->sphereImplicit, SIGNAL(clicked()), this, SLOT(SphereImplicitExample()));
    connect(uiw->resetcameraButton, SIGNAL(clicked()), this, SLOT(ResetCamera()));
    connect(uiw->wireframe, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));
    connect(uiw->radioShadingButton_1, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));
    connect(uiw->radioShadingButton_2, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));

    // Widget edition
    connect(meshWidget, SIGNAL(_signalEditSceneLeft(const Ray&)), this, SLOT(editingSceneLeft(const Ray&)));
    connect(meshWidget, SIGNAL(_signalEditSceneRight(const Ray&)), this, SLOT(editingSceneRight(const Ray&)));
}


/*!
\brief Generates and displays the mesh of a box.
*/
void MainWindow::BoxMeshExample()
{
    Mesh boxMesh = Mesh(Box(1.0));

    std::vector<Color> cols;
    cols.resize(boxMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(boxMesh, cols, boxMesh.VertexIndexes());
    UpdateGeometry();
}

/*!
\brief Generates and displays the mesh of a sphere.
*/
void MainWindow::SphereMeshExemple()
{
    auto start = std::chrono::high_resolution_clock::now();

    Mesh sphereMesh = Mesh(Sphere(Vector(0,0,0), 1, 50));

    std::vector<Color> cols;
    cols.resize(sphereMesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(sphereMesh, cols, sphereMesh.VertexIndexes());

    UpdateGeometry();//ne pas appeler pour debuger les points

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> float_ms = end - start;

    std::cout << "Sphere is " << float_ms.count() << " milliseconds" << std::endl;
}

/*!
\brief Generates and displays the mesh of a capsule.
*/
void MainWindow::CapsuleMeshExemple()
{
    auto start = std::chrono::high_resolution_clock::now();

    Mesh capsuleMesh = Mesh(Capsule(Vector(0,0,0), 1, 2, 50));

    std::vector<Color> cols;
    cols.resize(capsuleMesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(capsuleMesh, cols, capsuleMesh.VertexIndexes());

    UpdateGeometry();//ne pas appeler pour debuger les points

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> float_ms = end - start;

    std::cout << "Capsule is " << float_ms.count() << " milliseconds" << std::endl;
}

/*!
\brief Generates and displays the mesh of a torus.
*/
void MainWindow::TorusMeshExemple()
{
    auto start = std::chrono::high_resolution_clock::now();

    Mesh torusMesh = Mesh(Torus(Vector(0,0,0) ,2 ,5 ,50 ,50));

    std::vector<Color> cols;
    cols.resize(torusMesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(torusMesh, cols, torusMesh.VertexIndexes());

    UpdateGeometry();//ne pas appeler pour debuger les points

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> float_ms = end - start;

    std::cout << "Torus is " << float_ms.count() << " milliseconds" << std::endl;

}

/*!
\brief Generates and displays the mesh of a cylindre.
*/
void MainWindow::CylindreMeshExemple()
{
    auto start = std::chrono::high_resolution_clock::now();
    Mesh cylindreMesh = Mesh(Cylinder(Vector(0,0,0) ,1, 2,50));

    std::vector<Color> cols;
    cols.resize(cylindreMesh.Vertexes());
    for (int i = 0; i < cols.size(); i++)
        cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

    meshColor = MeshColor(cylindreMesh, cols, cylindreMesh.VertexIndexes());

    UpdateGeometry();//ne pas appeler pour debuger les points

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> float_ms = end - start;

    std::cout << "Cylinder is " << float_ms.count() << " milliseconds" << std::endl;

}

/*!
\brief Generates and displays the mesh of a sphere created implicitly.
*/
void MainWindow::SphereImplicitExample()
{
  AnalyticScalarField implicit;

  Mesh implicitMesh;
  implicit.Polygonize(31, implicitMesh, Box(2.0));
  std::vector<Color> cols;
  cols.resize(implicitMesh.Vertexes());
  for (size_t i = 0; i < cols.size(); i++)
    cols[i] = Color(0.8, 0.8, 0.8);

  meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
  UpdateGeometry();
}

/*!
\brief Generates an image on the User's Interface and the statistics of the image.
*/
void MainWindow::UpdateGeometry()
{
    meshWidget->ClearAll();
    meshWidget->AddMesh("BoxMesh", meshColor);

    uiw->lineEdit->setText(QString::number(meshColor.Vertexes()));
    uiw->lineEdit_2->setText(QString::number(meshColor.Triangles()));

    UpdateMaterial();
}

/*!
\brief Generates an image on the User's Interface.
*/
void MainWindow::UpdateMaterial()
{
    meshWidget->UseWireframeGlobal(uiw->wireframe->isChecked());

    if (uiw->radioShadingButton_1->isChecked())
        meshWidget->SetMaterialGlobal(MeshMaterial::Normal);
    else
        meshWidget->SetMaterialGlobal(MeshMaterial::Color);
}

/*!
\brief Sets the camera on a default value on the User's Interface.
*/
void MainWindow::ResetCamera()
{
    meshWidget->SetCamera(Camera(Vector(-10.0), Vector(0.0)));
}

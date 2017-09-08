import controlP5.*;


//variable to access ControlP5 class
ControlP5 cp5;
String fp = "Choose a file homo";


void setup() {
  
  size(550, 650);
  cp5 = new ControlP5(this);
  
  
cp5.addButton("File")
  .setSize(130,35)
  .setColorBackground(color(255,0,0))
  .setColorActive(color(255,0,0))
  .setPosition(43,190)
  .setLabel("Hi choose a file");
  
    cp5.addTextfield("Filepath")
    .setLabel("Filepath Goes Here")
    .setText(fp)
    .setPosition(43, 269)
    .setSize(300, 30);
  
    cp5.addButton("Exit")
    .setPosition(43, 550)
    .setSize(130, 35);
  
}
  
void draw() {
  //continuosly draw background and update text statuses
  background(10, 30, 30);
     
     cp5.addTextfield("Filepath")
    .setLabel("Filepath Goes Here")
    .setColorBackground(color(255,255,255))
    .setText(fp)
    .setColor(100)
    .setPosition(43, 269)
    .setSize(300, 30);
}

public void File() {
  selectInput("Choose a file","Filer");
}

void Filer(File selection) {
  if (selection == null){
    fp = "Nope";
  }
  else{
    fp = selection.getAbsolutePath();
  }
}

void Exit() {
  exit();
}
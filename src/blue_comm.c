#include "blue_comm.h"

void start_blue(void * q) {
  queue_t *queue=(queue_t *)q;
  blue_com_t comm;
 
  initialize(&comm);
  
  sync_mode(&comm);

  communicate(&comm);
  //TODO:make sure to reset once a connection is broken.
}

int initialize(blue_com_t *bs){
  //initialize stats
  /*
  inquiry_info *li=NULL;
  int max_rsp,num_rsp;
  int dev_id,sock,len,flags;
  dev_id=hci_get_route(NULL);
  sock= hci_open_dev(dev_id);
  if (dev<0 || sock <0 ){
    return 1;
  }
  len=8;
  max_rsp=255;

  li=(inquiry_info*)malloc(max_rsp *sizeof(inquiry_info));
  
  num_rsp=hci_inquiry(dev_id,len,max_rsp,NULL,&li,flags);
  
  if (num_rsp<0) return 2;
  
  for (i=0;i<num_rsp ;i++) {
    ba2str(&(ii+i)->bdaddr, addr);
    memset(name, 0, sizeof(name));
    if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), name, 0) < 0)
      strcpy(name, "[unknown]");
    printf("%s  %s\n", addr, name);
  }
*/
  
  bs->sock=socket(AF_BLUETOOTH,SOCK_STREAM,BTPROTO_RFCOMM);
  bs->locaddr.rc_family=AF_BLUETOOTH;
  bs->locaddr.rc_bdaddr=*BDADDR_ANY;
  bs->locaddr.rc_channel=(uint8_t) 1;
  bs->queue=create_queue(STACK_HEAP_SPACE);
  
  //  free(li);
  //close(sock);
  //return 0;
  
}

int sync_mode(blue_com_t *bcom) {
  //set listen mode for new connections
  bind(s,(struct sockaddr *)&(bcom->loc_addr),sizeof(bcom->loc_addr));
  listen(s,1);
  bcom->client = accept(s, (struct sockaddr *) &rem_addr, &opt); //define
  //throw out?
  //TODO: optimize client? may be faster not storing in struct
  return 0;
 }


void communicate (blue_com_t *bcom) {
  //initiates listening part
  //TODO: decide whether to make blocking or non-blocking IO
  char buf;
  while (1){
    buf=0;
    //memset(buf,0,INSTRUCT_SIZE);
    read(bcom->client,&buf,1);
    push_Q(bcom->queue,buf);
   
  }
}

import { IonAvatar, IonCol, IonGrid, IonItem, IonLabel, IonRow } from "@ionic/react";
import './ModeSelector.css';

const modeSelector: React.FC = ()=>{
    return(
        <IonGrid>
            <IonRow  class="ion-text-center">
                <IonCol size="6">
                    <IonLabel class="labels">Party</IonLabel>
                </IonCol>
                <IonCol size="6">
                    <IonLabel class="labels">Relax</IonLabel>
                </IonCol>
            </IonRow>
            <IonRow  >
                <IonCol size="6" class="ion-padding-start">
                   <IonItem button lines="none" class="ion-padding-start" >
                        <IonAvatar > 
                            <img src = "assets/images/party.jpg" alt= "Party"/>
                        </IonAvatar>
                    </IonItem>
                </IonCol>
                <IonCol size="6" class="ion-padding-start">
                   <IonItem button lines="none" class="ion-padding-start" className="items" >
                        <IonAvatar > 
                            <img src = "assets/images/relax.jpg" alt= "relax"/>
                        </IonAvatar>
                        
                    </IonItem>
                </IonCol>
            </IonRow>

            <IonRow  class="ion-text-center ion-no-padding">
                <IonCol size="6">
                    <IonLabel className="labels">Study</IonLabel>
                </IonCol>
                <IonCol size="6">
                    <IonLabel className="labels">Sexy</IonLabel>
                </IonCol>
            </IonRow>

            <IonRow  >
                <IonCol size="6" class="ion-padding-start">
                   <IonItem button lines="none" class="ion-padding-start" >
                        <IonAvatar > 
                            <img src = "assets/images/study.jpg" alt= "Study"/>
                        </IonAvatar>
                        
                    </IonItem>
                </IonCol>
                <IonCol size="6" class="ion-padding-start">
                   <IonItem button lines="none" class="ion-padding-start" >
                        <IonAvatar > 
                            <img src = "assets/images/sexy.jpg" alt= "Sexy"/>
                        </IonAvatar>
                        
                    </IonItem>
                </IonCol>
            </IonRow>
        </IonGrid>
    )
}

export default modeSelector;
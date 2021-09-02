import { IonButton, IonCol, IonGrid, IonIcon, IonItem, IonRange, IonRow } from "@ionic/react"
import { sunny,sunnyOutline } from 'ionicons/icons';
import { useState } from "react";


const ColorSelector: React.FC = () =>{
    const [valueColor, setValueColor] = useState("warning")
    
    const rangeChgHandler = (e: CustomEvent)=>{
        setValueColor(
            e.detail.value==0?"warning":
            e.detail.value==2?"primary":
            e.detail.value==4?"success":
            e.detail.value==6?"danger":"light");
    }

    return(
        <IonGrid >
            <IonRow><p>Color Selector</p> </IonRow>
            <IonRow>
                <IonCol>
                    <IonItem >
                         <IonRange min={0} max={8} step={2} snaps={true} onIonChange={e=>rangeChgHandler(e)}>
                          <IonIcon slot="end" icon={sunny} size="large" color={valueColor}/>
                         </IonRange>
                    </IonItem>
                </IonCol>
            </IonRow>           
        </IonGrid>
    )
}
export default ColorSelector;
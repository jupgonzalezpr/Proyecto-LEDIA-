import { IonContent, IonHeader, IonPage, IonTitle, IonToolbar } from '@ionic/react';
import ColorSelector from '../components/ColorSelector';
import ImageContainer from '../components/ImageContainer';
import ModeSelector from '../components/ModeSelector'
import './Tab2.css';

const Tab2: React.FC = () => {
  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle>Room Configuration</IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent fullscreen>
        <IonHeader collapse="condense">
          <IonToolbar>
            <IonTitle size="large">Tab 2</IonTitle>
          </IonToolbar>
        </IonHeader>
        <ImageContainer/>
        <ColorSelector/>
        <ModeSelector/>
      </IonContent>
    </IonPage>
  );
};

export default Tab2;
